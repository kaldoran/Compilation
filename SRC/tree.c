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

/** Définit le dernier frère d'un noeud. (G -> D) */
#define LAST_BROTHER(NODE) for(; NODE->next != NULL; NODE = NODE->next)

/** Racine d'un arbre. */
#define ROOT(NODE) for(; NODE->father != NULL; NODE = NODE->father)

/** Teste si un noeud est orphelin. */
#define ORPHAN_TEST(NODE)                                               \
  if(NODE->father == NULL && NODE->prev == NULL && NODE->next == NULL)  \
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
    for(tmp = t; tmp != NULL; free(t))
    {    
      if(t->children != NULL && list_add_node(stack, t->children) == NULL)
	fatal_error("tree_free");
      
       if(fun != NULL)
	 fun(t->value);
       
       tmp = t->next; 
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
    for(; t != NULL; t = t->next)
    {    
      if(fun != NULL) 
	fun(t);

      t->depth = t->father == NULL ? 0 : t->father->depth;
     
      if(t->children != NULL && list_add_node(stack, t->children) == NULL)
	fatal_error("tree_foreach_node");
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

Tree *tree_add_nodes(Tree *parent, ...)
{
  va_list pa;
  Tree *node, *brother;

  /* Parcours des nouveaux fils. */
  va_start(pa, parent);

  /* Aucun fils à ajouter. */
  if((node = va_arg(pa, Tree*)) == NULL)
  {
    va_end(pa);
    return NULL;
  }

  ORPHAN_TEST(node);

  /* Si parent n'a aucun fils. */
  if(parent->children == NULL)
  {
    parent->children = node;
    node->father = parent;
    brother = node;
  }
  /* Sinon on ajoute le premier nouveau fils à la fin des fils. */
  else
  {
    brother = parent->children;
    LAST_BROTHER(brother);
    brother->next = node;
    node->prev = brother;
    node->father = parent;
  }

  /* Ajout des autres fils. */
  while((node = va_arg(pa, Tree*)) != NULL)
  {
    ORPHAN_TEST(node);
    LAST_BROTHER(brother);
    brother->next = node;
    node->prev = brother;
    node->father = parent;
  }

  va_end(pa);

  return parent;
}

Tree *tree_node_insert(Tree *parent, int pos, Tree *node)
{
  Tree *children = parent->children;
  int i;
  
  if(node == NULL)
    return NULL; /* Noeud vide... */

  ORPHAN_TEST(node);

  /* Définition du père du noeud. */
  node->father = parent;
  
  /* Aucun fils. */
  if(children == NULL)
    parent->children = node;
  
  /* Fin. */
  else if(pos < 0)
  {
    LAST_BROTHER(children);
    children->next = node;
    node->prev = children;
  }

  /* Recherche d'un emplacement. */
  else
  {
    for(i = 0; i < pos && children->next != NULL; i++);
  
    /* Début. */
    if(children->prev == NULL)
    {
      parent->children = node;
      node->next = children;
      children->prev = node;
    }

    /* Autre. */
    else
    {
      node->next = children;
      node->prev = children->prev;

      if(children->prev != NULL)
	children->prev->next = node;

      children->prev = node;
    }
  }

  return node;
}

Tree *tree_add_brother(Tree *origin, Tree *brother)
{
  ORPHAN_TEST(brother);
  LAST_BROTHER(origin);
  
  origin->next = brother;
  brother->prev = origin;

  brother->father = origin->father;

  return brother;
}
