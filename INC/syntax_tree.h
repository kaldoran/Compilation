/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.h                                                */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 09:06:39                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _SYNTAX_TREE_
#define _SYNTAX_TREE_

#include "tree.h"

/** Types des noeuds de l'arbre. */
#define AT_UNKNOWN 0

/** Opérateurs. */
#define AT_OP_PLUS  1
#define AT_OP_MINUS 2
#define AT_OP_MULT  3
#define AT_OP_DIV   4
#define AT_OP_MOD   5

/** Comparaisons. */
#define AT_CMP_E  6
#define AT_CMP_G  7
#define AT_CMP_GE 8
#define AT_CMP_L  9
#define AT_CMP_LE 10

/** Conditions. */
#define AT_CND_AND 11
#define AT_CND_OR  12
#define AT_CND_NOT 13

/** Fonctions prédéfinies. */
#define AT_FUN_READ  14
#define AT_FUN_WRITE 15

/** Constantes. */
#define AT_CST_STRING 16

/** Structure d'un arbre abstrait. */
typedef Tree Syntax_tree;

/** Valeur d'un noeud d'un arbre abstrait. */
typedef union Value_syntax_node
{
  int i;   /* Entier. */
  float f; /* Flottant. */
  char c;  /* Caractère */
  char *s; /* Chaîne. */
} Value_syntax_node;

/** Structure d'un noeud d'un arbre abstrait. */
typedef struct Syntax_node 
{ 
  unsigned char type;       /* Type du noeud. */
  Value_syntax_node value;  /* Valeur du noeud. */
} Syntax_node;

/** Libération d'un noeud d'un arbre abstrait. */
/* %param : Noeud à supprimer. */
void syntax_node_free(void *node);

/** Libération d'un arbre abstrait. */
/* %param TREE : Arbre à libérer. */
#define syntax_tree_free(TREE) tree_free(TREE, syntax_node_free)

/** Affiche un noeud d'un arbre abstrait. */
/* %param node : Noeud à afficher. */
void syntax_tree_print_node(Syntax_tree *node);

/** Affiche un arbre abstrait. */
/* %param TREE : Arbre à afficher. */
#define syntax_tree_print(TREE) tree_foreach_node(TREE, syntax_tree_print_node)

#endif /* _SYNTAX_TREE_ INCLUDED */
