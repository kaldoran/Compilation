/* ---------------------------------------------------------------------- */
/* Filename: main.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-09 - 19:17:51                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#define USE_BASIC_TYPE 0 /* basic_type_* Inutiles dans le main */
#include "lexeme_table.h"
#include "regions_table.h"
#include "private_tree.h"
#include "error.h"

void exemple(Hashtable *h)
{
  Hashkey soif, desmots, ref;

  /* Ajout de lexèmes. */
  lexeme_table_add(h, "bonjour");
  desmots = lexeme_table_add(h, "desmots");
  lexeme_table_add(h, "demo");
  soif = lexeme_table_add(h, "soif");
  lexeme_table_add(h, "tete");

  /* Affichage des lexèmes. */
  printf("Lexeme table:\n");
  lexeme_table_print(h);

  /* Ajouts de champs. */
  symbol_table_add(h, soif, 10, 15, NULL, 12);
  symbol_table_add(h, soif, 38, 54, (void *)0x12, 21);
 
  ref = hashtable_get_key(h, "tete");
  symbol_table_add(h, ref, 128, 12, (void *)0x5416, 47);

  /* Affichage des champs de déclarations. */
  printf("\nSymbol table:\n");
  symbol_table_print(h);

  return;
}

int main(void)
{
  /* Initialisation */
  Hashtable *hashtable = hashtable_new();
  
  if(!symbol_table_init())
    fatal_error("Unable to init symbol table");
 
  lexeme_table_init(hashtable);
  
  /* Execution */
  exemple(hashtable);

  /* Libération */
  symbol_table_free();
  hashtable_free(hashtable, free);
  regions_table_free();
  
  exit(EXIT_SUCCESS);
}
