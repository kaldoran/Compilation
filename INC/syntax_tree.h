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
#define AT_OP_PLUS   1 /* plus */
#define AT_OP_MINUS  2 /* minus */
#define AT_OP_MULT   3 /* mult */
#define AT_OP_DIV    4 /* div */
#define AT_OP_MOD    5 /* mod */

/** Opérateurs d'affectations */
#define AT_OPR_PLUSE  6	/* plus equal */
#define AT_OPR_MINE   7	/* minus equal */
#define AT_OPR_MULTE  8	/* mult equal */
#define AT_OPR_DIVE   9	/* div equal */
#define AT_OPR_MODE  10	/* mod equal */

/** Opérateurs binaire */
#define AT_OB_INC       11	//increment
#define AT_OB_DEC       12	//decrement

/** Comparaisons. */
#define AT_CMP_E  	    13	//equal
#define AT_CMP_G        14	//greater	than
#define AT_CMP_GE       15	//greater or equal
#define AT_CMP_L        16 	//lower than
#define AT_CMP_LE       17	//lower or equal
#define AT_CMP_DF       18	//different

/** Conditions. */
#define AT_CND_AND      19	//and
#define AT_CND_OR       20	//or
#define AT_CND_NOT	    21	//not	

/** Fonctions prédéfinies. */
#define AT_FUN_READ     22	//read
#define AT_FUN_WRITE    23	//write
#define AT_FUN_RAND     24	//random

/** Contrôleurs */
#define AT_CTL_IF	    25	//if
#define AT_CTL_ELSE     26	//else
#define AT_CTL_WHILE    27	//while
#define AT_CTL_ARRAY    28	//array
#define AT_CTL_STRUCT   29 	//structure
#define AT_CTL_PROC	    30	//procedure
#define AT_CTL_FUN      31	//function
#define AT_CTL_RETURN   32	//return
#define AT_CTL_SWITCH   33	//switch
#define AT_CTL_CASE     34	//case
#define AT_CTL_DEFAULT  35	//default
#define AT_CTL_BREAK    36	//break
#define AT_CTL_CONTINUE 37	//continue
#define AT_CTL_TERNAIRE 38    //ternaire

/** Constantes. */
#define AT_CST_STRING   39	/* string */
#define AT_CST_REEL     40	//real
#define AT_CST_BOOL     41	//boolean
#define AT_CST_CHAR     42	//char
#define AT_CST_INT      43	//integer
#define AT_CST_EMPTY    44	/* empty node */

/** Structure d'un arbre abstrait. */
typedef Tree Syntax_tree;

/** Valeur d'un noeud d'un arbre abstrait. */
typedef union Syntax_node_value
{
  int i;   /* Entier. */
  float f; /* Flottant. */
  char c;  /* Caractère */
  char *s; /* Chaîne. */
} Syntax_node_value;

/** Structure du contenu d'un noeud d'un arbre. */
typedef struct Syntax_node_content
{ 
  unsigned char type;       /* Type du noeud. */
  Syntax_node_value value;  /* Valeur du noeud. */
} Syntax_node_content;

/** Crée un nouveau noeud d'un arbre abstrait. */
/* %param type : Type du noeud à ajouter. */
/* %return : Le nouveau noeud. 
   Appelle fatal_error en cas d'erreur d'allocation. */
Syntax_tree *syntax_tree_node_new(unsigned char type);

/** Libération de la valeur d'un noeud d'un arbre abstrait. */
/* %param : Valeur du noeud à supprimer. */
void syntax_node_free(void *value);

/** Libération d'un arbre abstrait. */
/* %param TREE : Arbre à libérer. */
#define syntax_tree_free(TREE) tree_free(TREE, syntax_node_free)

/** Ajoute un frère à un noeud. */
/* %param ORIGIN : Noeud d'origine. */
/* %param BROTHER : Frère à ajouter. */
/* %return : Le noeud d'origine ou NULL en cas d'erreur. */
#define syntax_tree_add_brother(ORIGIN, BROTHER) tree_add_brother(ORIGIN, BROTHER)

/** Ajoute un fils à un noeud. */
/* %param PARENT : Noeud père du fils à ajouter. */
/* %param NODE : Fils à ajouter. */
/* %return : Le noeud inseré. */
#define syntax_tree_add_son(PARENT, NODE) tree_node_append(PARENT, NODE)

/** Affiche un noeud d'un arbre abstrait. */
/* %param node : Noeud à afficher. */
void syntax_tree_print_node(Syntax_tree *node);

/** Affiche un arbre abstrait. */
/* %param TREE : Arbre à afficher. */
#define syntax_tree_print(TREE) tree_foreach_node(TREE, syntax_tree_print_node)

#endif /* _SYNTAX_TREE_ INCLUDED */
