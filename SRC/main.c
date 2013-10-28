/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-21 - 17:25:41                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include "kernel.h"

extern int yyparse(void);
extern int yylex_destroy(void);

/* Table de Hachage. (Lexemes, déclarations...)
   Table déclarée dans yacc.y */
extern Hashtable *hashtable;

#define PRINT_TITLE(STR) \
  printf("\n# ------------------------------\n%s\n# ------------------------------\n\n", STR);

int main(void)
{
  int ret;

  /* Initialisation */
  hashtable = hashtable_new();
  symbol_table_init(hashtable);
  lexeme_table_init(hashtable);

  /* Execution */
  if(!(ret = yyparse()))
  {
    /* Affichage */
    PRINT_TITLE("LEXEMES");
    lexeme_table_print(hashtable);
    
    PRINT_TITLE("SYMBOLS");
    symbol_table_print(hashtable);

    PRINT_TITLE("REGIONS");
    regions_table_print();
  }
  
  /* Libération */
  yylex_destroy();
  hashtable_free(hashtable, symbol_table_free);
  regions_table_free();
  
  exit(ret);
}
