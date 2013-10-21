/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.c                                                */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 09:09:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "syntax_tree.h"
#include "error.h"

Syntax_tree *syntax_tree_node_new(unsigned char type)
{
  Syntax_tree *tree;
  Syntax_node_content *snode = malloc(sizeof *snode);

  if(snode == NULL || (tree = tree_node_new(snode)) == NULL)
    fatal_error("syntax_tree_node_new");

  snode->type = type;
  return tree;
}

void syntax_node_free(void *value)
{
  Syntax_node_content *n = value;

  if(n->type == AT_CST_STRING)
    free(n->value.s);
  free(n);

  return;
}

Syntax_tree *syntax_tree_add_brother(Syntax_tree *origin, Syntax_tree *brother)
{
  if(tree_node_is_root(origin))
    return NULL; /* Racine. */

  if(tree_node_append(tree_node_get_father(origin), brother) == NULL)
    fatal_error("syntax_tree_add_brother");

  return origin;
}

void syntax_tree_print_node(Syntax_tree *node)
{
  int i, depth = tree_node_get_depth(node);
  Syntax_node_content *snode;

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

