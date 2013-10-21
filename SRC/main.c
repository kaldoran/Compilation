/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-09 - 19:17:51                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#define USE_BASIC_TYPE 0 /* basic_type_* inutile dans le main. */
#include "kernel.h"
#include "yacc.h"

extern int yyparse(void);

int main(void)
{
  /* Initialisation */
  Hashtable *hashtable = hashtable_new();
  
  if(!symbol_table_init())
    fatal_error("Unable to init symbol table");
 
  lexeme_table_init(hashtable);
  
  /* Execution */
  yyparse();

  /* Libération */
  symbol_table_free();
  hashtable_free(hashtable, free);
  regions_table_free();
  
  exit(EXIT_SUCCESS);
}
