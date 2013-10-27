/* ---------------------------------------------------------------------- */
/* Filename: symbol_table.c                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 14:53:05                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#include "list.h"
#include "description_table.h"
#include "error.h"

/* Nombre de types de bases. (int, float, char, bool) */
#define SYMBOL_BASIC_MAX 4

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Déclarations des types de bases. */
static Symbol *symbol_basic[SYMBOL_BASIC_MAX];

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/** Affiche un champ de déclaration. */
/* %param : Champ à afficher. */
static void symbol_print(void *symbol);

/* ---------------------------------------------------------------------- */

static void symbol_print(void *symbol)
{
  Symbol *s = symbol;
  
  for(; s != NULL; s = s->next) 
    printf("\n    (Type=%d, Region=%d, Index=%p, Size=%lu)", s->type, s->region, 
	   s->index, (long unsigned int)s->exec);

    printf("\n");

  return;
}

/* ---------------------------------------------------------------------- */

void symbol_table_init(Symbol_table *table)
{
  Symbol *sym;
  char *type[] = {"int", "float", "bool", "char"};
  int i;
  
  for(i = 0; i < SYMBOL_BASIC_MAX - 1; i++)
  {
    if((sym = malloc(sizeof *sym)) == NULL)
      fatal_error("symbol_table_init");

    sym->type = SYMBOL_TYPE_BASE;
    sym->exec = 1;
    sym->next = NULL;
    sym->index = NULL;
    sym->region = 0;

    symbol_basic[i] = sym;

    if(hashtable_add_value(table, type[i], sym) == NULL)
      fatal_error("lexeme_table_init");
  }

  return;  
}

void symbol_table_free(void *sym)
{
  Symbol *s_base = sym, *s_next;

  for(s_next = s_base; s_next != NULL; s_base = s_next)
  {
    s_next = s_base->next;

    /* Libération description. */
    switch(s_base->type)
    {
      case SYMBOL_TYPE_STRUCT:
        procedure_free(s_base->index); 
        break;
      case SYMBOL_TYPE_ARRAY:
        array_free(s_base->index); 
        break;
      case SYMBOL_TYPE_PROCEDURE:
        procedure_free(s_base->index); 
        break;
      case SYMBOL_TYPE_FUNCTION:
        function_free(s_base->index); 
        break;

      default: break;
    }

    /* Libération déclaration courante. */
    free(s_base);
  }

  return;
}

bool symbol_table_add(Symbol_table *table, Hashkey hkey, Type type, 
		      int region, Index_t index, size_t exec)
{
  Symbol *sym = malloc(sizeof *sym);
  Symbol *origin;

  if(sym == NULL)
    return false; /* Bad alloc. */
  
  sym->type = type;
  sym->region = region;
  sym->index = index;
  sym->next = NULL;
  sym->exec = exec;
    
  /* Si le champ est déjà pris. */
  if((origin = hashtable_get_value_by_key(table, hkey)) != NULL)
  {
    sym->next = origin;
    hashtable_set_value_by_key(table, hkey, sym);
  }
  /* Ajout du symbole si aucune déclaration identique. */
  else if(!hashtable_set_value_by_key(table, hkey, sym))
  {
    free(sym);
    return false;
  }

  return true;
}

Symbol *symbol_table_get(Hashtable *table, Hashkey hkey, int region)
{
  Symbol *origin = hashtable_get_value_by_key(table, hkey);

  for(; origin != NULL; origin = origin->next)
    if(origin->region == region)
      return origin; /* Trouvé ! */

  return NULL; /* Non trouvé. */
}

Index_t symbol_table_get_basic(int basic_num)
{
  if(basic_num <= 0 || basic_num > SYMBOL_BASIC_MAX)
    return NULL;
  return symbol_basic[basic_num - 1];
}

void symbol_table_print(Symbol_table *table)
{
  hashtable_print(table, symbol_print);
  return;
}
