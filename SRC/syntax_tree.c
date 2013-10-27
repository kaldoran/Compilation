/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.c                                                */
/* Authors: ABHAMON Ronan, REYNAUD Nicolas                                */
/* Date: 2013-09-18 - 09:09:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "private_tree.h"
#include "syntax_tree.h"
#include "error.h"

/** Profondeur max d'affichage de l'arbre. */
#define MAX_DEPTH 1000

/** Tableau servant à l'affichage de l'arbre. */
static char *node_name[] = {"unknown", "plus", "minus", "mult", "div", "mod", "plus equal", "minus equal", 
			    "mult equal", "div equal", "mod equal", "increment", "decrement", "pincrement", 
			    "pdecrement", "equal", "greater than", "greater or equal", "lower than", 
			    "lower or equal", "different", "and", "or", "not", "read", "write", "random", 
			    "if", "else", "while", "do while", "for", "array", "structure", "procedure", 
			    "function", "return", "switch", "case", "default", "break", "continue", 
			    "ternaire", "appel", "string", "real", "boolean", "char", "integer", "egal", 
			    "empty node"};

/** Tableau de marquage de profondeur pour l'affichage de l'arbre. */
static char arr_p[1000] = {0};

Syntax_tree *syntax_tree_node_new(unsigned char type)
{
  Syntax_tree *tree;
  Syntax_node_content *snode = malloc(sizeof *snode);

  if(snode == NULL || (tree = tree_node_new(snode)) == NULL)
    fatal_error("syntax_tree_node_new");

  snode->type = type;
  return tree;
}

Syntax_tree *syntax_tree_node_int_new(int value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_INT);
  ((Syntax_node_content *)tree->value)->value.i = value;
  return tree;
}

Syntax_tree *syntax_tree_node_float_new(float value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_FLOAT);
  ((Syntax_node_content *)tree->value)->value.f = value;
  return tree;
}

Syntax_tree *syntax_tree_node_char_new(char value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_CHAR);
  ((Syntax_node_content *)tree->value)->value.c = value;
  return tree;
}

Syntax_tree *syntax_tree_node_bool_new(bool value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_BOOL);
  ((Syntax_node_content *)tree->value)->value.c = value;
  return tree;
}

Syntax_tree *syntax_tree_node_string_new(const char *value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_STRING);
  ((Syntax_node_content *)tree->value)->value.s = (char *)value;
  return tree;
}

Syntax_tree *syntax_tree_node_hkey_new(Hashkey value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_HKEY_INDEX);
  ((Syntax_node_content *)tree->value)->value.hkey = value;
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

void syntax_tree_print_node(Syntax_tree *node)
{
  int i, depth = tree_node_get_depth(node);
  Syntax_node_content *snode;

  if(depth >= MAX_DEPTH)
  {
    fprintf(stderr, "Error: The tree depth is so big !\n");
    return;
  }

  arr_p[depth] = node->next != NULL;

  for(i = 0; i < depth; i++)
  {
    if(node->prev == NULL && i == depth - 1)
      arr_p[i] ? printf("├───") : printf("└───"); 
    else if(arr_p[i])
      printf("│   ");
    else
      printf("    ");
    
    /* Code en commentaire à conserver en cas de détection d'erreur dans la génération de l'arbre. */

    /*
    if(arr_p[i] && node->prev == NULL && i == depth - 1)
      printf("├───");
    else if(node->prev == NULL && i == depth - 1)
      printf("└───");
    else if(arr_p[i])
      printf("│   ");
    else
      printf("    ");

    */
  }     

  if(node->prev == NULL)
  {
    if(node->next != NULL || node->children != NULL || node->father == NULL)
      printf("┬─");
    else if(node->next == NULL && node->children == NULL)
      printf("──");
  }
  else 
    (node->children != NULL || node->next != NULL) ? printf("├─") : printf("└─");

  /*
  if(node->father == NULL && node->prev == NULL)
    printf("┬─");
  else if(node->prev == NULL && (node->next != NULL || node->children != NULL))
    printf("┬─");
  else if(node->next == NULL && node->children == NULL && node->prev == NULL)
    printf("──");
  else if(node->children != NULL || node->next != NULL)
    printf("├─");
 
  else 
    printf("└─");
  */

  /* Contenu adresse */
  snode = tree_node_get_value(node);
  
  if(snode->type >= 0 && snode->type < AT_SIZE) 
    printf("%s\n", node_name[snode->type]);

  return;
}
