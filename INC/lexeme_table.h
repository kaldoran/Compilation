/* ---------------------------------------------------------------------- */
/* Filename: lexeme_table.h                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-13 - 18:52:28                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _LEXEME_TABLE_
#define _LEXEME_TABLE_

#include "symbol_table.h"

/** Structure d'une table de lexèmes. */
typedef Hashtable Lexeme_table;

/** Initialise la table des lexèmes. */
/* Définit les types de base. Suppose donc que les basic_type_* du fichier
   "symbol_table.h" sont initialisés. En cas d'erreur, le programme est
   directement quitté avec affichage du type de l'erreur. */
void lexeme_table_init(Lexeme_table *table);

/** Ajoute un lexème dans la table. */
/* %param TABLE : Table des lexèmes. */
/* %param LEXEME : Lexème à ajouter. */
/* %return : Retourne NULL en cas d'erreur ou la clef du lexème sinon. (Hashkey) */
#define lexeme_table_add(TABLE, LEXEME) hashtable_add_value(TABLE, LEXEME, NULL)

/** Récupère un lexème dans la table. */
/* %param TABLE : Table contenant le lexème. */
/* %param HASHKEY : Clef du lexème. */
/* %return : NULL en cas d'erreur ou le lexème sinon. */
#define lexeme_table_get(TABLE, HASHKEY) hashtable_get_id(TABLE, HASHKEY)

/** Affiche la table des lexèmes. */
/* %param TABLE : Table à afficher. */
#define lexeme_table_print(TABLE) hashtable_print(TABLE, NULL)

#endif /* _LEXEME_TABLE_ INCLUDED */
