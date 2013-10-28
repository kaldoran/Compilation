/* ---------------------------------------------------------------------- */
/* Filename: regions_stack.c                                              */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-27 - 17:34:02                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdlib.h>
#include "regions_stack.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Taille de la pile des régions. */
static unsigned int regions_stack_size = 0;

/** Pile. */
static Region_node *start = NULL;

/* ---------------------------------------------------------------------- */

void regions_stack_free(void)
{
  Region_node *node;

  for(node = start; start != NULL; node = start)
  {
    start = start->next;
    free(node);
  }

  regions_stack_size = 0;

  return;
}

int regions_stack_push(int region)
{
  Region_node *new_node = malloc(sizeof *new_node);

  if(new_node == NULL)
    return -1; /* Bad alloc. */

  new_node->next = start;
  new_node->region = region;
  start = new_node;
  regions_stack_size++;

  return region;
}

int regions_stack_pop(void)
{
  Region_node *node;
  int region;

  if(start == NULL)
    return 0; /* Pile vide. */

  region = start->region;
  node = start;
  start = start->next;
  
  free(node);
  regions_stack_size--;

  return region;
}

int regions_stack_top(void)
{
  if(start == NULL)
    return 0; /* Pile vide. */
  return start->region;
}

unsigned int regions_stack_get_size(void)
{
  return regions_stack_size;
}

Region_node *regions_stack_get_node(void)
{
  return start;
}
