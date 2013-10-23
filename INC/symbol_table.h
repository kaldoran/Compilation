/* ---------------------------------------------------------------------- */
/* Filename: symbol_table.h                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 14:53:09                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _SYMBOL_TABLE_
#define _SYMBOL_TABLE_

#include "hashtable.h"

/** Types de symboles. */
#define SYMBOL_UNKNOWN        0
#define SYMBOL_TYPE_BASE      1
#define SYMBOL_TYPE_STRUCT    2
#define SYMBOL_TYPE_ARRAY     3
#define SYMBOL_TYPE_VAR       4
#define SYMBOL_TYPE_PROCEDURE 5
#define SYMBOL_TYPE_FUNCTION  6

/** Types de bases. */
#define SYMBOL_BASIC_INT   1
#define SYMBOL_BASIC_FLOAT 2
#define SYMBOL_BASIC_BOOL  3
#define STMBOL_BASIC_CHAR  4

/** Index sur table */
typedef void* Index_t;

/** Structure d'un symbole. (champ de déclaration) */
typedef struct Symbol
{
  char type;           /* Type de symbole. */ 
  int region;          /* Région contenant la déclaration. */
  Index_t index;       /* Index sur table. (symboles ou description) */
  struct Symbol *next; /* Symbole suivant de même nom. */
  size_t exec;         /* Taille à l'execution. */
} Symbol;

/** Structure d'une table des déclarations. */
typedef Hashtable Symbol_table;

/** Type d'une déclaration. */
typedef unsigned char Type;

/** Initialise la table des déclarations. */
/* Définit les types de base + Init des lexèmes de base. */
/* %param table : Table des déclarations. */
void symbol_table_init(Symbol_table *table);

/** Libère une liste de symboles. */
/* %param sym : Premier symbole d'une liste. */
void symbol_table_free(void *sym);

/** Ajouter une déclaration dans la table. */
/* %param table : Table des déclarations. */
/* %param hkey : Clef lexicographique de l'identificateur. */
/* %param type : Type de la déclaration. */
/* %param area : Région de la déclaration. */
/* %param index : Index sur table. */
/* %param exec : Taille à l'execution. */
/* %return : false en cas d'erreur mémoire ou true en cas de réussite. */
bool symbol_table_add(Symbol_table *table, Hashkey key, Type type, 
		      int region, Index_t index, size_t exec);
 
/** Obtenir un champ de déclaration de la table. */
/* Association de noms. */
/* %param table : Table des déclarations. */
/* %param hkey : Numéro lexicographique de la déclaration. */
/* %param region : Numéro de la région contenant la déclaration. */
/* %return : Le champ de déclaration correspondant ou NULL si non trouvé. */
Symbol *symbol_table_get(Symbol_table *table, Hashkey hkey, int region);

/** Retourne l'index d'un type de Base dans la table. */
/* %param : Numéro du Type de base à récupérer. */
/* %return : Retourne un index sur le champ correspondant ou NULL si basic_num n'est pas bon. */
Index_t symbol_table_get_basic(int basic_num);

#define SBASIC_INT   symbol_table_get_basic(SYMBOL_BASIC_INT)   /* Type 1 */
#define SBASIC_FLOAT symbol_table_get_basic(SYMBOL_BASIC_FLOAT) /* Type 2 */
#define SBASIC_BOOL  symbol_table_get_basic(SYMBOL_BASIC_BOOL)  /* Type 3 */
#define SBASIC_CHAR  symbol_table_get_basic(SYMBOL_BASIC_CHAR)  /* Type 4 */

/** Affiche la table des déclarations. */
/* %param table : Table des déclarations. */
void symbol_table_print(Symbol_table *table);

#endif /* _SYMBOL_TABLE_ INCLUDED */

