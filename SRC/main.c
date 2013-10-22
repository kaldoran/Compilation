/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-21 - 17:25:41                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

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
  symbol_table_init();
   
  /* Execution */
  yyparse();

  /* Libération */
  hashtable_free(hashtable, symbol_table_free);
  regions_table_free();
  
  exit(EXIT_SUCCESS);
}
