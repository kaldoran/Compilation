/* ---------------------------------------------------------------------- */
/* Filename: tree.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-15 - 23:23:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "private_tree.h"
#include "tree.h"
#include "list.h"
#include "error.h"

/** Définit le premier frère d'un noeud. (D -> G) */
#define FIRST_BROTHER(NODE) for(; NODE->prev != NULL; NODE = NODE->prev)

/** Définit le dernier frère d'un noeud. (G -> D) */
#define LAST_BROTHER(NODE) for(; NODE->next != NULL; NODE = NODE->next)

/** Met à jours le père des noeuds. */
#define SET_FATHER(NODE, FATHER)                                         \
  if(1)                                                                  \
  {                                                                      \
    for(; NODE->next != NULL; NODE->father = FATHER, NODE = NODE->next); \
    NODE->father = FATHER;                                               \
  }

/** Racine d'un arbre. */
#define ROOT(NODE) for(; NODE->father != NULL; NODE = NODE->father)

/** Teste si un noeud est orphelin. */
#define ORPHAN_TEST(NODE)                                               \
  if(NODE->father != NULL)                                              \
  {                                                                     \
    fprintf(stderr, "Exception : This node is not an orphan node !\n"); \
    return NULL;                                                        \
  }

Tree *tree_node_new(void *value)
{
  Tree *t;

  if((t = calloc(1, sizeof *t)) == NULL)
    return NULL; /* Bad alloc */

  t->value = value;

  return t;
}

void tree_free(Tree *t, void (*fun)(void *value))
{
  /* La pile système n'est pas utilisée pour libérer l'arbre,
     il est préférable d'utiliser une structure de pile ici */

  List *stack;
  Tree *tmp;

  if(t == NULL)
    return;

  /* On remonte jusqu'au noeud père */
  ROOT(t);

  if((stack = list_new()) == NULL || list_add_node(stack, t) == NULL)
    fatal_error("tree_free");
  
  /* Tant qu'il reste un noeud */
  while((t = list_shift_node(stack)) != NULL)
    for(; t != NULL; t = tmp)
    {   
      if(t->children != NULL && list_add_node(stack, t->children) == NULL)
	fatal_error("tree_free");
      
       if(fun != NULL)
	 fun(t->value);
 
       tmp = t->next;
       free(t);
    }

  list_free(stack, NULL);

  return;
}

void tree_foreach_node(Tree *t, void (*fun)(Tree *node))
{
  List *stack;

  ROOT(t);
  
  if((stack = list_new()) == NULL || list_add_node(stack, t) == NULL)
    fatal_error("tree_foreach_node");
  
  while((t = list_shift_node(stack)) != NULL)
    for(; t != NULL; t = t->children)
    {    
      t->depth = t->father == NULL ? 0 : t->father->depth + 1;

      if(t->next != NULL && list_add_node(stack, t->next) == NULL)
	fatal_error("tree_foreach_node");

      if(fun != NULL) 
	fun(t);
    }

  list_free(stack, NULL);

  return;
}

Tree *tree_get_root(Tree *t)
{
  ROOT(t);
  return t;
}

bool tree_node_is_root(Tree *node)
{
  return node->father == NULL;
}

bool tree_node_is_leaf(Tree *node)
{
  return node->children == NULL;
}

void *tree_node_get_value(Tree *node)
{
  return node->value;
}

int tree_node_get_depth(Tree *node)
{
  return node->depth;
}

Tree *tree_node_get_father(Tree *t)
{
  return t->father;
}

Tree *tree_node_insert(Tree *parent, int pos, Tree *node)
{
  Tree *children = parent->children;
  Tree *cp_node;

  if(node == NULL)
    return NULL; /* Noeud vide... */

  ORPHAN_TEST(node);

  /* Définition du père du(des) noeud(s). */
  FIRST_BROTHER(node);
  cp_node = node;
  SET_FATHER(node, parent);
  
  /* Aucun fils. */
  if(children == NULL)
    parent->children = cp_node;

  /* Fin. */
  else if(pos < 0)
  {
    LAST_BROTHER(children);
    children->next = cp_node;
    cp_node->prev = children;
  }

  /* Recherche d'un emplacement. */
  else
  {
    for(;pos-- > 0 && children->next != NULL; children = children->next);
  
    /* Début. */
    if(children->prev == NULL)
    {
      parent->children = cp_node;
      node->next = children;
      children->prev = node;
    }

    /* Autre. */
    else
    {
      node->next = children;

      children->prev->next = cp_node;
      cp_node->prev = children->prev;

      children->prev = node;
    }
  }

  return node;
}

Tree *tree_add_brother(Tree *origin, Tree *brother)
{
  Tree *cp_brother;

  ORPHAN_TEST(brother);
  LAST_BROTHER(origin);
  FIRST_BROTHER(brother);
  cp_brother = brother;
  SET_FATHER(brother, origin->father);

  origin->next = cp_brother;
  cp_brother->prev = origin;

  return brother;
}
