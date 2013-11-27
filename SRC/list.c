/* ---------------------------------------------------------------------- */
/* Filename: list.c                                                       */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-09-09 - 19:21:16                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "private_list.h"
#include "list.h"

List *list_new(void)
{
  return calloc(1, sizeof(List));
}

void list_free(List *l, void (*fun)(void *value))
{
  List_node *cur, *next;

  if(l == NULL)
    return; /* Liste inexistante */

  for(cur = l->start; cur != NULL; cur = next)
  {
    next = cur->next;

    if(fun != NULL)
      fun(cur->value);

    free(cur);
  }

  free(l);

  return;
}

unsigned int list_get_size(List *l)
{
  return l->size;
}

bool list_is_empty(List *l)
{
  return l->size == 0;
}

void *list_add_node(List *l, void *value)
{
  List_node *new_node = malloc(sizeof *new_node);

  if(new_node == NULL)
    return NULL; /* Bad alloc */

  new_node->value = value;
  new_node->next = l->start;

  if(l->start == NULL)
    l->end = new_node;

  l->start = new_node;
  l->size++;

  return value;
}

void *list_push_node(List *l, void *value)
{
  List_node *new_node = malloc(sizeof *new_node);

  if(new_node == NULL)
    return NULL; /* Bad alloc */

  new_node->value = value;
  new_node->next = NULL;

  if(l->end == NULL)
    l->start = new_node;
  else
    l->end->next = new_node;

  l->end = new_node;
  l->size++;

  return value;
}

void *list_shift_node(List *l)
{
  List_node *node = l->start;
  void *value;

  if(node == NULL)
    return NULL; /* Liste vide */

  if((l->start = node->next) == NULL)
    l->end = NULL;

  value = node->value;
  free(node);
  l->size--;

  return value;
}

void *list_pop_node(List *l)
{
  List_node *node = l->end, *ns;
  void *value;

  if(node == NULL)
    return NULL; /* Liste vide */

  if(l->size == 1)
    l->start = l->end = NULL;
  else
  {
    for(ns = l->start; ns->next != node; ns = ns->next);
    ns->next = NULL;
    l->end = ns;
  }

  value = node->value;
  free(node);
  l->size--;

  return value;
}

void list_map(List *l, void (*fun)(void *value))
{
  List_node *ln;

  for(ln = l->start; ln != NULL; ln = ln->next)
    fun(ln->value);

  return;
}
