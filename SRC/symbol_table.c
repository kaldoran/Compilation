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

bool symbol_table_init(void)
{
  if((basic_type_int   = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_float = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_bool  = malloc(sizeof(Symbol))) == NULL ||
     (basic_type_char  = malloc(sizeof(Symbol))) == NULL)
  {
    symbol_table_free();
    return false; /* Bad alloc */
  }

  SET_BASIC_TYPE(basic_type_int, int);
  SET_BASIC_TYPE(basic_type_float, float);
  SET_BASIC_TYPE(basic_type_bool, bool);
  SET_BASIC_TYPE(basic_type_char, char);
    
  return true;
}

void symbol_table_free(void)
{
  free(basic_type_int); 
  free(basic_type_float);
  free(basic_type_bool);
  free(basic_type_char);

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
