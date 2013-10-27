/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-21 - 17:25:41                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include "kernel.h"
#include "yacc.h"

extern int yyparse(void);
extern int yylex_destroy(void);

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

#include "private_tree.h"

void test2(void)
{
  /* Racine */
  Syntax_tree *tree = syntax_tree_node_new(AT_OPR_PLUSE);
  Syntax_tree *tree2, *tree3, *tree4, *tree5, *tree6;

  printf("\n\nARBRE:\n");

  syntax_tree_add_son(tree, syntax_tree_node_new(AT_OB_INC));
  syntax_tree_add_son(tree, tree2 = syntax_tree_node_new(AT_OB_DEC));
  syntax_tree_add_son(tree2, tree3 = syntax_tree_node_new(AT_CND_NOT));
  syntax_tree_add_son(tree, tree6 = syntax_tree_node_new(AT_FUN_WRITE));

  syntax_tree_add_brother(tree, syntax_tree_node_new(AT_OPR_MODE));
  syntax_tree_add_brother(tree3, tree5 = syntax_tree_node_new(AT_CTL_SWITCH));
  syntax_tree_add_brother(tree, syntax_tree_node_new(AT_FUN_WRITE));
  syntax_tree_add_brother(tree2, tree4 = syntax_tree_node_new(AT_FUN_WRITE));
  syntax_tree_add_son(tree4, syntax_tree_node_new(AT_FUN_WRITE));
  syntax_tree_add_son(tree5, tree4 = syntax_tree_node_new(AT_FUN_READ));
  syntax_tree_add_son(tree4, tree5 = syntax_tree_node_new(AT_FUN_READ));
  syntax_tree_add_son(tree5, syntax_tree_node_new(AT_OB_INC));
  syntax_tree_add_son(tree6, syntax_tree_node_new(AT_OP_MULT));
  syntax_tree_add_brother(tree4, syntax_tree_node_new(AT_CTL_PROC));

  syntax_tree_print(tree);
  syntax_tree_free(tree);
  printf("\n");

}

void test3()
{/*
  Field fi;
  Dimension di;
  Parameter pa;
  Hashkey a = NULL;

  Structure *s = structure_new(10, a);
  Array *ar = array_new(10, 0);
  Function *f = function_new(0, 10);
  Procedure *p = procedure_new(10);

  int i;

  f->return_type = 0;

  for(i=0; i<10; i++){
  
      fi.hkey = a;
      fi.type = 0;

      di.bound_lower = 1;
      di.bound_upper = 11;

      pa.hkey = a;
      pa.type = 0;

      s->field[i] = fi;
      ar->dimension[i] = di;
      f->params[i] = pa;
      p->params[i] = pa;
  }
     

  printf("borne inf : %d\n", ar->dimension[9].bound_lower);
  printf("borne sup : %d\n", ar->dimension[9].bound_upper);
  printf("type : %p\n", s->field[9].type);
  printf("type : %p\n", f->params[9].type);
  printf("type : %p\n", p->params[9].type);
  printf("return type : %p\n", f->return_type);


  structure_free(s);
  array_free(ar);
  function_free(f);
  procedure_free(p);
 */
}

int main(void)
{
  /* Initialisation */
  hashtable = hashtable_new();
  symbol_table_init(hashtable);
  lexeme_table_init(hashtable);

  /* Execution */
  yyparse();

  /* test();
  test2();
  test3(); */
 
  /* Affichage */
  symbol_table_print(hashtable);

  /* Libération */
  yylex_destroy();
  hashtable_free(hashtable, symbol_table_free);
  regions_table_free();
  
  exit(EXIT_SUCCESS);
}
