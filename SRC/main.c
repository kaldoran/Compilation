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

void test(void)
{
  Hashkey a, b;

  lexeme_table_add(hashtable, "bonjour");
  a = lexeme_table_add(hashtable, "manger");
  lexeme_table_add(hashtable, "dormir");
  lexeme_table_add(hashtable, "boire");
  b = lexeme_table_add(hashtable, "roupiller");
  lexeme_table_add(hashtable, "coucou");
  lexeme_table_add(hashtable, "ahah");

  symbol_table_add(hashtable, a, 0, 0, 0, 0);
  symbol_table_add(hashtable, a, 1, 0, 0, 0);
  symbol_table_add(hashtable, a, 2, 0, 0, 0);

  symbol_table_add(hashtable, b, 3, 0, 0, 0);
  symbol_table_add(hashtable, b, 4, 0, 0, 0);
  symbol_table_add(hashtable, b, 5, 0, 0, 0);

  a = hashtable_get_key(hashtable, "coucou");
  symbol_table_add(hashtable, a, 6, 0, 0, 0);

  fprintf(stdout, "LEXEMES:\n");
  lexeme_table_print(hashtable);

  fprintf(stdout, "\n\nDECLARATIONS:\n");
  symbol_table_print(hashtable);
}

int main(void)
{
  /* Initialisation */
  hashtable = hashtable_new();
  symbol_table_init(hashtable);
   
  /* Execution */
  /* yyparse(); */

  test();

  /* Libération */
  hashtable_free(hashtable, symbol_table_free);
  regions_table_free();
  
  exit(EXIT_SUCCESS);
}
