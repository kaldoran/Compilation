/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.c                                                */
/* Authors: ABHAMON Ronan, REYNAUD Nicolas                                */
/* Date: 2013-09-18 - 09:09:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "private_tree.h"
#include "syntax_tree.h"
#include "error.h"
#include "mystring.h"
#include "string.h"
#include "save.h"

/** Accès aux valeurs d'un noeud. */
#define STVALUE(TREE) ((Syntax_node_content *)TREE->value)

/** Profondeur max d'affichage de l'arbre. */
#define MAX_DEPTH 1000

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/** Attribue la valeur d'un noeud en fonction de son type en lisant dans un flux. */
/* %param table : Table des lexèmes. */
/* %param stream : Flux d'entrée. */
/* %param tree : Noeud à modifier. */
static void syntax_tree_read_value(Lexeme_table *table, FILE *stream, Syntax_tree *tree);

/* ---------------------------------------------------------------------- */

static void syntax_tree_read_value(Lexeme_table *table, FILE *stream, Syntax_tree *tree)
{
  Syntax_node_content *content = tree->value;
  static char buffer[255] = "";
  int i = 0;
  Index_t *index_array = index_array_get();

  switch(content->type)
  {
    /* Constantes. */
    case AT_CST_STRING: fgets(buffer, 255, stream);
      if((content->value.s = mystrdup(buffer)) == NULL)
        fatal_error("syntax_tree_read_value");
      content->value.s[strlen(buffer) - 1] = '\0';
      break;
    case AT_CST_FLOAT: fscanf(stream, "%f ", &content->value.f); break;
    case AT_CST_BOOL:  fscanf(stream, "%c ", &content->value.c); break;
    case AT_CST_CHAR:  fscanf(stream, "%c ", &content->value.c); break;
    case AT_CST_INT:   fscanf(stream, "%d ", &content->value.i); break;
    
    /* IDF. */
    case AT_VAR:       
    case AT_CTL_CALL:
      fscanf(stream, "%d %s ", &i, buffer);
      content->value.var.hkey = hashtable_get_key(table, buffer);
      content->value.var.type = index_array[i];
      break;

    /* Numéro de champ de structure. */
    case AT_HKEY_INDEX: fscanf(stream, "%d ", &content->value.i); break;
     
    default: break;
  }

  return;
}

/* ---------------------------------------------------------------------- */

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
  STVALUE(tree)->value.i = value;
  return tree;
}

Syntax_tree *syntax_tree_node_float_new(float value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_FLOAT);
  STVALUE(tree)->value.f = value;
  return tree;
}

Syntax_tree *syntax_tree_node_char_new(char value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_CHAR);
  STVALUE(tree)->value.c = value;
  return tree;
}

Syntax_tree *syntax_tree_node_bool_new(bool value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_BOOL);
  STVALUE(tree)->value.c = value;
  return tree;
}

Syntax_tree *syntax_tree_node_string_new(const char *value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CST_STRING);
  STVALUE(tree)->value.s = (char *)value;
  return tree;
}

Syntax_tree *syntax_tree_node_var_new(Hashkey value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_VAR);
  STVALUE(tree)->value.var.hkey = value;
  STVALUE(tree)->value.var.type = symbol_table_get(NULL, value);
  return tree;
}

Syntax_tree *syntax_tree_node_call_new(Hashkey value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_CTL_CALL);
  STVALUE(tree)->value.var.hkey = value;
  STVALUE(tree)->value.var.type = symbol_table_get(NULL, value);
  return tree;
}

Syntax_tree *syntax_tree_node_hkey_new(Hashkey value)
{
  Syntax_tree *tree = syntax_tree_node_new(AT_HKEY_INDEX);

  STVALUE(tree)->value.var.hkey = value;
  STVALUE(tree)->value.var.type = NULL; 

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

  static const char *node_name[] = {"unknown", "plus", "minus", "mult", "div", "mod", "plus equal", 
                                    "minus equal", "mult equal", "div equal", "mod equal", "increment", 
                                    "decrement", "pincrement", "pdecrement", "equal", "greater than",
                                    "greater or equal",  "lower than", "lower or equal", "different", 
                                    "and", "or", "not", "read", "write", "random", "if", "else", "while", 
                                    "do while", "for", "array", "structure", "procedure", "function", 
                                    "return", "switch", "case", "default", "break", "continue", "ternaire", 
                                    "appel", "string", "real", "boolean", "char", "integer", "set", "variable",
                                    "array index", "hkey index", "empty node"};
  
  static char arr_p[MAX_DEPTH] = {0};

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

  /* Contenu adresse */
  snode = tree_node_get_value(node);
  
  if(snode->type < AT_SIZE)
  {
    printf("%s", node_name[snode->type]);

    switch(snode->type)
    {
      case AT_VAR: 
	printf(" (%s)", lexeme_table_get(NULL, snode->value.var.hkey));
	break;
      case AT_CST_STRING:
	printf(" (%s)", snode->value.s);
	break;
      case AT_CST_FLOAT:
	printf(" (%f)", snode->value.f);
	break; 
      case AT_CST_BOOL:
	printf(snode->value.c ? " (true)" : " (false)");
	break;
      case AT_CST_CHAR:
	printf(" (%c)", snode->value.c);
	break;
      case AT_CST_INT:
	printf(" (%d)", snode->value.i);
	break;
      case AT_HKEY_INDEX:
	printf(" (Field: %d)", snode->value.i);
	break;
      default: break;
    }

    printf("\n");
  }
  else
    printf("NAME_ERROR\n");

  return;
}

Syntax_node_content *syntax_tree_node_get_content(Syntax_tree *node)
{
  return STVALUE(node);
}

void syntax_tree_save(FILE *stream, Syntax_tree *node)
{
  List *queue;
  Syntax_node_content *content;

  /* Ajout de la racine dans une file. */
  if((queue = list_new()) == NULL || list_push_node(queue, node) == NULL)
    fatal_error("syntax_tree_save");
  
  /* Premier élément de la file. */
  while((node = list_shift_node(queue)) != NULL)
  {
    /* Si noeud existant. */
    if(node != (void *)-1)
    {
      /* Ajout des fils/frere dans la file. */ 
      if(list_push_node(queue, ((node->children == NULL) ? (void *)-1 : node->children)) == NULL ||
         list_push_node(queue, ((node->next == NULL)  ? (void *)-1 : node->next)) == NULL)
        fatal_error("syntax_tree_save");

      /* Ecriture du noeud. */
      content = node->value;
      fprintf(stream, "%d ", content->type);

      switch(content->type)
      {
	/* Constantes. */
        case AT_CST_STRING: fprintf(stream, "\n%s\n", content->value.s); break;
        case AT_CST_FLOAT:  fprintf(stream, "%f ", content->value.f);    break;
        case AT_CST_BOOL:   fprintf(stream, "%c ", content->value.c);    break;
        case AT_CST_CHAR:   fprintf(stream, "%c ", content->value.c);    break;
        case AT_CST_INT:    fprintf(stream, "%d ", content->value.i);    break;

	/* IDF */ 
        case AT_VAR:        
        case AT_CTL_CALL: fprintf(stream, "%d %s ", index_array_get_id(content->value.var.type), 
				  hashtable_get_id(NULL, content->value.var.hkey)); break;

	/* Numéro de champ de structure. */
        case AT_HKEY_INDEX: fprintf(stream, "%d ", content->value.i); break;

        default: break;
      }
    }        
    else
      fprintf(stream, "-1 ");
  }

  /* Fin de l'arbre. */
  fprintf(stream, "-2\n");
  list_free(queue, NULL);

  return;
}

Syntax_tree *syntax_tree_load(Lexeme_table *table, FILE *stream)
{
  int type;
  List *queue;
  Syntax_tree *root, *node, *child, *brother;

  /* Type du noeud de la racine. */
  fscanf(stream, "%d ", &type);
  root = node = syntax_tree_node_new(type);
  syntax_tree_read_value(table, stream, node);

  /* Ajout de la racine dans une file. */
  if((queue = list_new()) == NULL || list_push_node(queue, node) == NULL)
    fatal_error("syntax_tree_save");

  while(1)
  {
    node = list_shift_node(queue);
    fscanf(stream, "%d ", &type);

    /* Fin de l'arbre. */
    if(type == -2) break;

    /* Fils. */
    if(type != -1)
    {
      child = syntax_tree_node_new(type);
      syntax_tree_read_value(table, stream, child);
      syntax_tree_add_son(node, child);

      if(list_push_node(queue, child) == NULL)
        fatal_error("syntax_tree_load");
    }
 
    /* Frère. */
    fscanf(stream, "%d ", &type);
    
    if(type != - 1)
    {
      brother = syntax_tree_node_new(type);
      syntax_tree_read_value(table, stream, brother);
      syntax_tree_add_brother(node, brother);

      if(list_push_node(queue, brother) == NULL)
        fatal_error("syntax_tree_load");
    }
  }
  
  list_free(queue, NULL);

  return root;
}
