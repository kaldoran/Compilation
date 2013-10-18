/* ---------------------------------------------------------------------- */
/* Filename: lexeme_table.c                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-13 - 18:52:22                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "lexeme_table.h"
#include "error.h"

void lexeme_table_init(Lexeme_table *table)
{
  /* Ajout des types de base */
  if(hashtable_add_value(table, "int", basic_type_int)     == NULL ||
     hashtable_add_value(table, "float", basic_type_float) == NULL ||
     hashtable_add_value(table, "bool", basic_type_bool)   == NULL ||
     hashtable_add_value(table, "char", basic_type_char)   == NULL)
    fatal_error("lexeme_table_init");
  return;
}
