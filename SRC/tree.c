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

  if(t == NULL)
    return;

  /* On remonte jusqu'au noeud père */
  for(; t->father != NULL; t = t->father);

  if((stack = list_new()) == NULL || list_add_node(stack, t) == NULL)
    fatal_error("tree_free");
  
  while((t = list_shift_node(stack)) != NULL)
    if(t->size_s != 0)
    {
      if(list_add_node(stack, t) == NULL || list_add_node(stack, t->sons[--t->size_s]) == NULL)
	 fatal_error("tree_free");
    }
    else
    {
      if(fun != NULL)
	free(t->value);
      free(t->sons);
      free(t);
    }
  
  list_free(stack, NULL);
  free(t);

  return;
}

void tree_foreach_node(Tree *t, void (*fun)(Tree *node))
{
  List *stack;
  int i;

  if((stack = list_new()) == NULL || list_add_node(stack, t) == NULL)
    fatal_error("tree_free");

  t->depth = 0;

  while((t = list_shift_node(stack)) != NULL)
  { 
    /* Appel de la fonction */
    if(fun != NULL) fun(t);

    /* Ajout des fils */
    for(i = t->size_s - 1; i >= 0; i--)
    {
      t->sons[i]->depth = t->depth + 1;

      if(list_add_node(stack, t->sons[i]) == NULL)
	fatal_error("tree_foreach_node");
    }
  }

  list_free(stack, NULL);

  return;
}

Tree *tree_get_root(Tree *t)
{
  for(; t->father != NULL; t = t->father);
  return t;
}

bool tree_node_is_root(Tree *node)
{
  return node->father == NULL;
}

bool tree_node_is_leaf(Tree *node)
{
  return node->size_s == 0;
}

void *tree_node_get_value(Tree *node)
{
  return node->value;
}

int tree_node_get_depth(Tree *node)
{
  return node->depth;
}

bool tree_add_nodes(Tree *parent, ...)
{
  va_list pa;
  int i;
  Tree *node, **new_sons;

  /* Vérification des arguments */
  va_start(pa, parent);
  for(i = 0; va_arg(pa, Tree*) != NULL; i++)
  va_end(pa);

  if(i == 0 || (new_sons = realloc(parent->sons, (parent->size_s + i) * sizeof *parent->sons)) == NULL)
    return false; /* Bad alloc */

  /* Application des noeuds */
  parent->sons = new_sons;
  va_start(pa, parent);
  for(; (node = va_arg(pa, Tree*)) != NULL;  parent->sons[parent->size_s++] = node, node->father = parent);
  va_end(pa);

  return true;
}

Tree *tree_node_insert(Tree *parent, int pos, Tree *node)
{
  Tree **new_sons;

  if(node == NULL)
    return NULL; /* Noeud vide... */

  if((new_sons = realloc(parent->sons, (parent->size_s + 1) * sizeof *parent->sons)) == NULL)
    return NULL; /* Bad alloc */

  parent->sons = new_sons;
  node->father = parent;

  if(pos < 0 || (unsigned int)pos > parent->size_s)
    parent->sons[pos = parent->size_s++] = node;
  else
  {
    memmove(parent->sons + pos + 1, parent->sons + pos, 
	    (parent->size_s++ - pos) * sizeof *parent->sons);
    parent->sons[pos] = node;
  }

  return node;
}
