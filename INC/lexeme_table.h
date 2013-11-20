/* ---------------------------------------------------------------------- */
/* Filename: lexeme_table.h                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-13 - 18:52:28                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _LEXEME_TABLE_
#define _LEXEME_TABLE_

#include "symbol_table.h"

/** Lexèmes de bases. */
#define LEXEME_BASIC_BOOL    1
#define LEXEME_BASIC_CHAR    2
#define LEXEME_BASIC_INT     3
#define LEXEME_BASIC_FLOAT   4
#define LEXEME_BASIC_STRING  5

/** Structure d'une table de lexèmes. */
typedef Hashtable Lexeme_table;

/** Initialise la table des lexèmes. */
/* Attention : Initialiser la table des déclarations avant ! */
/* %param table : Table des lexèmes. */
void lexeme_table_init(Lexeme_table *table);

/** Ajoute un lexème dans la table. */
/* %param TABLE : Table des lexèmes. */
/* %param LEXEME : Lexème à ajouter. */
/* %return : Retourne NULL en cas d'erreur ou la clef du lexème sinon. (Hashkey) */
#define lexeme_table_add(TABLE, LEXEME) hashtable_add_value(TABLE, LEXEME, NULL)

/** Récupère un nom de lexème dans la table. */
/* %param TABLE : Table contenant le lexème. */
/* %param HASHKEY : Clef du lexème. */
/* %return : NULL en cas d'erreur ou le lexème sinon. */
#define lexeme_table_get(TABLE, HASHKEY) hashtable_get_id(TABLE, HASHKEY)

/** Retourne la clef de Hachage d'un type de Base dans la table. */
/* %param : Numéro du Type de base à récupérer. */
/* %return : Retourne une clef de Hachage ou NULL si basic_num n'est pas bon. */
Hashkey lexeme_table_get_basic(int basic_num);

#define LBASIC_BOOL   lexeme_table_get_basic(LEXEME_BASIC_BOOL)   /* Type 1 */
#define LBASIC_CHAR   lexeme_table_get_basic(LEXEME_BASIC_CHAR)   /* Type 2 */
#define LBASIC_INT    lexeme_table_get_basic(LEXEME_BASIC_INT)    /* Type 3 */
#define LBASIC_FLOAT  lexeme_table_get_basic(LEXEME_BASIC_FLOAT)  /* Type 4 */
#define LBASIC_STRING lexeme_table_get_basic(LEXEME_BASIC_STRING) /* Type 5 */

/** Affiche la table des lexèmes. */
/* %param TABLE : Table à afficher. */
#define lexeme_table_print(TABLE) hashtable_print(TABLE, NULL)

#endif /* _LEXEME_TABLE_ INCLUDED */
