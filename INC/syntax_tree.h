/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.h                                                */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-09-18 - 09:06:39                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _SYNTAX_TREE_
#define _SYNTAX_TREE_

#include "tree.h"
#include "lexeme_table.h"
#include "description_table.h"

/** Nombre de types de noeuds. */
#define AT_SIZE AT_EMPTY + 1

/** Types des noeuds de l'arbre. */
#define AT_UNKNOWN 0 /* unknown */

/** Opérateurs. */
#define AT_OP_PLUS   1 /* plus */
#define AT_OP_MINUS  2 /* minus */
#define AT_OP_MULT   3 /* mult */
#define AT_OP_DIV    4 /* div */
#define AT_OP_MOD    5 /* mod */

/** Opérateurs d'affectations */
#define AT_OPR_PLUSE  6 /* plus equal */
#define AT_OPR_MINE   7 /* minus equal */
#define AT_OPR_MULTE  8 /* mult equal */
#define AT_OPR_DIVE   9 /* div equal */
#define AT_OPR_MODE  10 /* mod equal */

/** Opérateurs d'affectations binaires. */
#define AT_OB_INC 11 /* increment */
#define AT_OB_DEC 12 /* decrement */
#define AT_OB_PINC 13 /* pincrement */
#define AT_OB_PDEC 14 /* pdecrement */

/** Comparaisons. */
#define AT_CMP_E  15 /* equal */
#define AT_CMP_G  16 /* greater than */
#define AT_CMP_GE 17 /* greater or equal */
#define AT_CMP_L  18 /* lower than */
#define AT_CMP_LE 19 /* lower or equal */
#define AT_CMP_NE 20 /* different */

/** Algèbre bool. */
#define AT_CND_AND 21 /* and */
#define AT_CND_OR  22 /* or */
#define AT_CND_NOT 23 /* not */

/** Fonctions prédéfinies. */
#define AT_FUN_READ  24 /* read */
#define AT_FUN_WRITE 25 /* write */
#define AT_FUN_RAND  26 /* random */

/** Contrôleurs. */
#define AT_CTL_IF       27 /* if */
#define AT_CTL_ELSE     28 /* else */
#define AT_CTL_WHILE    29 /* while */
#define AT_CTL_DO_WHILE 30 /* do while */
#define AT_CTL_FOR      31 /* for */
#define AT_CTL_ARRAY    32 /* array */
#define AT_CTL_STRUCT   33 /* structure */
#define AT_CTL_PROC     34 /* procedure */
#define AT_CTL_FUN      35 /* function */
#define AT_CTL_RETURN   36 /* return */
#define AT_CTL_SWITCH   37 /* switch */
#define AT_CTL_CASE     38 /* case */
#define AT_CTL_DEFAULT  39 /* default */
#define AT_CTL_BREAK    40 /* break */
#define AT_CTL_CONTINUE 41 /* continue */
#define AT_CTL_TERNAIRE 42 /* ternaire */
#define AT_CTL_CALL     43 /* call */

/** Constantes. */
#define AT_CST_STRING 44 /* string */
#define AT_CST_FLOAT  45 /* real */
#define AT_CST_BOOL   46 /* boolean */
#define AT_CST_CHAR   47 /* char */
#define AT_CST_INT    48 /* integer */

/* Affectation. */
#define AT_EQUAL 49 /* set */

/* Variable et champs. */
#define AT_VAR         50 /* variable */
#define AT_ARRAY_INDEX 51 /* array index */
#define AT_HKEY_INDEX  52 /* hkey index */

/** Vide. */
#define AT_EMPTY 53 /* empty node */

/** Structure d'un arbre abstrait. */
typedef Tree Syntax_tree;

/** Valeur d'un noeud d'un arbre abstrait. */
typedef union Syntax_node_value
{
  int i;        /* Entier. */
  float f;      /* Flottant. */
  char c;       /* Caractère/Booléen. */
  char *s;      /* Chaîne. */
  Variable var; /* Variable. */
} Syntax_node_value;

/** Structure du contenu d'un noeud d'un arbre. */
typedef struct Syntax_node_content
{
  unsigned char type;      /* Type du noeud. */
  Syntax_node_value value; /* Valeur du noeud. */
} Syntax_node_content;

/** Crée un nouveau noeud d'un arbre abstrait. */
/* %param type : Type du noeud à ajouter. */
/* %return : Le nouveau noeud.
   Appelle fatal_error en cas d'erreur d'allocation. */
Syntax_tree *syntax_tree_node_new(unsigned char type);

/** Crée un nouveau noeud d'un arbre abstrait contenant une certaine valeur. */
/* %param value : Valeur du noeud. */
/* %return : Le noeud noeud.
   Appelle fatal_error en cas d'erreur d'allocation. */
Syntax_tree *syntax_tree_node_int_new(int value);
Syntax_tree *syntax_tree_node_float_new(float value);
Syntax_tree *syntax_tree_node_char_new(char value);
Syntax_tree *syntax_tree_node_bool_new(bool value);
Syntax_tree *syntax_tree_node_string_new(const char *value);
Syntax_tree *syntax_tree_node_var_new(Hashkey value);
Syntax_tree *syntax_tree_node_call_new(Hashkey value);
Syntax_tree *syntax_tree_node_hkey_new(Hashkey value);

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

/** Retourne le contenu d'un noeud. */
/* %param node : Noeud à évaluer. */
/* %return : La valeur du noeud. */
Syntax_node_content *syntax_tree_node_get_content(Syntax_tree *node);

/** Sauvegarde d'un arbre abstrait dans un flux. */
/* %param stream : Flux de sortie. */
/* %param node : Arbre à sauvegarder. */
void syntax_tree_save(FILE *stream, Syntax_tree *node);

/** Charge un arbre abstrait dans un flux. */
/* %param table : Table des lexèmes. */
/* %param stream : Flux d'entrée. */
/* %return : Arbre à charger. */
Syntax_tree *syntax_tree_load(Lexeme_table *table, FILE *stream);

#endif /* _SYNTAX_TREE_ INCLUDED */
