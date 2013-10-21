/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-21 - 17:25:41                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#define USE_BASIC_TYPE 0
#include "kernel.h"
#include "yacc.h"

extern int yyparse(void);

/* Table de Hachage. (Lexemes, déclarations...)
   Table déclarée dans yacc.y */
extern Hashtable *hashtable;

int main(void)
{
  /* Initialisation */
  hashtable = hashtable_new();
  
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
