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
  int i;

  Structure *s;
  Array *ar;
  Function *f;
  Procedure *p;
  
  
  lexeme_table_add(hashtable, "bonjour");
  a = lexeme_table_add(hashtable, "manger");
  lexeme_table_add(hashtable, "dormir");
  lexeme_table_add(hashtable, "boire");
  b = lexeme_table_add(hashtable, "roupiller");
  lexeme_table_add(hashtable, "coucou");
  lexeme_table_add(hashtable, "ahah");
  
  
  /*s = structure_new(10, a);*/
  /*ar = array_new(10, 0);*/
  /*f = function_new(0, 10);*/
  /*p = procedure_new(10);*/

  /*f->return_type = 0;*/

  /*for(i=0; i<10; i++){*/
      /*Field fi;*/
      /*Dimension di;*/
      /*Parameter pa;*/

      /*fi.hkey = a;*/
      /*fi.type = 0;*/

      /*di.bound_lower = 1;*/
      /*di.bound_upper = 11;*/

      /*pa.hkey = a;*/
      /*pa.type = 0;*/

      /*s->field[i] = fi;*/
      /*ar->dimension[i] = di;*/
      /*f->params[i] = pa;*/
      /*p->params[i] = pa;*/
  /*}*/
     

  /*printf("borne inf : %d\n", ar->dimension[9].bound_lower);*/
  /*printf("borne sup : %d\n", ar->dimension[9].bound_upper);*/
  /*printf("type : %d\n", (int)(s->field[9].type));*/
  /*printf("type : %d\n", (int)f->params[9].type);*/
  /*printf("type : %d\n", (int)p->params[9].type);*/
  /*printf("return type : %d\n", (int)p->return_type);*/


  /*structure_free(s);*/
  /*array_free(ar);*/
  /*function_free(f);*/
  /*procedure_free(p);*/



  symbol_table_add(hashtable, a, 0, 0, s, 0);
  symbol_table_add(hashtable, a, 1, 0, a, 0);
  symbol_table_add(hashtable, a, 2, 0, f, 0);

  symbol_table_add(hashtable, b, 3, 0, p, 0);
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
