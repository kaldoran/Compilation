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
#include "error.h"

/** Définition du contenu des types de base */
#define SET_BASIC_TYPE(BASIC_TYPE, TYPE) \
  if(1)                                  \
  {                                      \
    BASIC_TYPE->type = SYMBOL_TYPE_BASE; \
    BASIC_TYPE->exec = sizeof(TYPE);     \
    BASIC_TYPE->next = NULL;             \
    BASIC_TYPE->index = NULL;            \
    BASIC_TYPE->region = 0;              \
  }

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
  Symbol *basic_type_int   = NULL; /* 1 */
  Symbol *basic_type_float = NULL; /* 2 */
  Symbol *basic_type_bool  = NULL; /* 3 */
  Symbol *basic_type_char  = NULL; /* 4 */

  if((basic_type_int   = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_float = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_bool  = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_char  = malloc(sizeof(Symbol))) == NULL)
    fatal_error("symbol_table_init");

  /* Définition des bases. */
  SET_BASIC_TYPE(basic_type_int, int);
  SET_BASIC_TYPE(basic_type_float, float);
  SET_BASIC_TYPE(basic_type_bool, bool);
  SET_BASIC_TYPE(basic_type_char, char);
    
  /* Ajout des types de base. */
  if(hashtable_add_value(table, "int", basic_type_int)     == NULL ||
     hashtable_add_value(table, "float", basic_type_float) == NULL ||
     hashtable_add_value(table, "bool", basic_type_bool)   == NULL ||
     hashtable_add_value(table, "char", basic_type_char)   == NULL)
    fatal_error("lexeme_table_init");

  return;  
}

void symbol_table_free(void *sym)
{
  Symbol *s_base = sym, *s_next;

  for(s_next = s_base; s_next != NULL; s_base = s_next)
  {
    s_next = s_base->next;
    free(s_base);
  }

  return;
}

bool symbol_table_add(Symbol_table *table, Hashkey hkey, unsigned char type, 
		      int region, Index_t index, size_t exec)
{
  Symbol *sym = malloc(sizeof *sym);
  Symbol *origin;

  if(sym == NULL)
    return false; /* Bad alloc */
  
  sym->type = type;
  sym->region = region;
  sym->index = index;
  sym->next = NULL;
  sym->exec = exec;
    
  /* Si le champ est déjà pris */
  if((origin = hashtable_get_value_by_key(table, hkey)) != NULL)
  {
    sym->next = origin;
    hashtable_set_value_by_key(table, hkey, sym);
  }
  /* Ajout du symbole si aucune déclaration identique */
  else if(!hashtable_set_value_by_key(table, hkey, sym))
  {
    free(sym);
    return false;
  }

  return true;
}

void symbol_table_print(Symbol_table *table)
{
  hashtable_print(table, symbol_print);
  return;
}
