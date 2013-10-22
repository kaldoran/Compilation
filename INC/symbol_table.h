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

/** Structure d'une table des déclarations. */
typedef Hashtable Symbol_table;

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
bool symbol_table_add(Symbol_table *table, Hashkey key, unsigned char type, 
		      int region, Index_t index, size_t exec);
 
/** Affiche la table des déclarations. */
/* %param table : Table des déclarations. */
void symbol_table_print(Symbol_table *table);

#endif /* _SYMBOL_TABLE_ INCLUDED */

