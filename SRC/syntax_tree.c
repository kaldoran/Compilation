/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.c                                                */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 09:09:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "syntax_tree.h"

void syntax_node_free(void *node)
{
  Syntax_node *n = node;

  if(n->type == AT_CST_STRING)
    free(n->value.s);
  free(n);

  return;
}

void syntax_tree_print_node(void *node)
{
  int i, depth = tree_node_get_depth(node);
  Syntax_node *snode;

  for(i = 0; i < depth; i++)
    printf("   ");

  /* Contenu adresse */
  snode = tree_node_get_value(node);
  
  switch(snode->type)
  {

    default:
      fprintf(stderr, "Unknown node !\n");
      break;
  }

  return;
}

