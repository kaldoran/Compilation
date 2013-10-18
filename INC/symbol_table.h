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

/** Types de base. */
/* Définir la constante USE_BASIC_TYPE à 0 pour ne pas les utiliser dans un fichier. */
#if (! defined USE_BASIC_TYPE) || (USE_BASIC_TYPE)
  static Symbol *basic_type_int   = NULL; /* 1 */
  static Symbol *basic_type_float = NULL; /* 2 */
  static Symbol *basic_type_bool  = NULL; /* 3 */
  static Symbol *basic_type_char  = NULL; /* 4 */
#endif

/** Structure d'une table des déclarations. */
typedef Hashtable Symbol_table;

/** Initialise la table des déclarations. */
/* Définit les types de base. */
/* %return : false en cas d'erreur mémoire ou true en cas de réussite. */
bool symbol_table_init(void);

/** Libère les types de base. */
void symbol_table_free(void);

/** Ajouter une déclaration dans la table. */
/* %param table : Table des déclarations. */
/* %param hkey : Clef lexicographique de l'identificateur. */
/* %param type : Type de la déclaration. */
/* %param area : Région de la déclaration. */
/* %param index : Index sur table. */
/* %param exec : Taille à l'execution. */
/* %return : false en cas d'erreur mémoire ou true en cas de réussite. */
bool symbol_table_add(Symbol_table *table, Hashkey key, unsigned char type, 
		      int region, Index_t index, size_t exec);
 
/** Affiche la table des déclarations. */
/* %param table : Table des déclarations. */
void symbol_table_print(Symbol_table *table);

#endif /* _SYMBOL_TABLE_ INCLUDED */

