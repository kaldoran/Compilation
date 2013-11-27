/* ---------------------------------------------------------------------- */
/* Filename: lexeme_table.c                                               */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-27 - 18:55:11                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdlib.h>
#include "lexeme_table.h"

/* Nombre de lexemes de bases. (int, float, char, bool, string) */
#define LEXEME_BASIC_MAX 5

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Déclarations des types de bases. */
static Hashkey lexeme_basic[LEXEME_BASIC_MAX];

/* ---------------------------------------------------------------------- */

void lexeme_table_init(Lexeme_table *table)
{
  lexeme_basic[0] = hashtable_get_key(table, "bool");
  lexeme_basic[1] = hashtable_get_key(table, "char");
  lexeme_basic[2] = hashtable_get_key(table, "int");
  lexeme_basic[3] = hashtable_get_key(table, "float");
  lexeme_basic[4] = hashtable_get_key(table, "string");

  return;
}

Hashkey lexeme_table_get_basic(int basic_num)
{
  if(basic_num <= 0 || basic_num > LEXEME_BASIC_MAX)
    return NULL;
  return lexeme_basic[basic_num - 1];
}
