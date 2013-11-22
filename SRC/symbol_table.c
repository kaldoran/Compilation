/* ---------------------------------------------------------------------- */
/* Filename: symbol_table.c                                               */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 14:53:05                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "description_table.h"
#include "regions_stack.h"
#include "error.h"
#include "symbol_table.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Déclarations des types de bases. */
static Symbol *symbol_basic[SYMBOL_BASIC_MAX];

/** Mauvaise compilation liée aux données. */
bool bad_compil = false;

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
  {
    printf("\n    (Type=");

    switch(s->type)
    {
      case SYMBOL_TYPE_BASE:      printf("BASE");                               break;
      case SYMBOL_TYPE_STRUCT:    printf("STRUCT");  structure_print(s->index); break;
      case SYMBOL_TYPE_ARRAY:     printf("ARRAY");   array_print(s->index);     break;
      case SYMBOL_TYPE_VAR:       printf("VAR");                                break;
      case SYMBOL_TYPE_PROCEDURE: printf("PROC");    procedure_print(s->index); break;
      case SYMBOL_TYPE_FUNCTION:  printf("FUNC");    function_print(s->index);  break;
      default: printf("UNKNOWN"); break;
    }

    printf(", Region=%d, Index=%p, Size=%lu, Adress=%p)", s->region, s->index, 
           (long unsigned int)s->exec, (void *)s);
  }
  
  printf("\n");

  return;
}

/* ---------------------------------------------------------------------- */

Symbol *symbol_new(char type, int region, Index_t index, size_t exec)
{
  Symbol *sym = malloc(sizeof *sym);

  if(sym == NULL)
    return NULL; /* Bad alloc. */
  
  sym->type = type;
  sym->region = region;
  sym->index = index;
  sym->next = NULL;
  sym->exec = exec;
    
  return sym;
}

void symbol_table_init(Symbol_table *table)
{
  Symbol *sym;
  const char *type[] = {"bool", "char", "int", "float", "string"};
  int i;
  
  for(i = 0; i < SYMBOL_BASIC_MAX; i++)
  {
    if((sym = symbol_new(SYMBOL_TYPE_BASE, -1, NULL, 1)) == NULL)
      fatal_error("symbol_table_init");

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
        structure_free(s_base->index); 
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
  Symbol *sym;
  Symbol *origin;
  
  if((sym = symbol_new(type, region, index, exec)) == NULL)
    return false;

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

Symbol *symbol_table_get(Hashtable *table, Hashkey hkey)
{
  Symbol *start = hashtable_get_value_by_key(table, hkey), *origin;
  Region_node *node = regions_stack_get_node();
  extern int line_num;
 
  /* Parcours de la pile des régions. */
  for(; node != NULL; node = node->next)
    /* Parcours des déclarations de même nom. */
    for(origin = start; origin != NULL; origin = origin->next)
      if(origin->region == node->region)
        return origin; /* Trouvé ! */

  /* Si pas dans la pile, peut-être au niveau -1 (Soit le niveau 0 du programme). */
  for(origin = start; origin != NULL; origin = origin->next)
    if(origin->region == -1)
      return origin; /* Trouvé ! */
 
  /* Non trouvé. */
  bad_compil = true;
  fprintf(stderr, "Line %d - Unable to find the declaration of \"%s\"\n", line_num, 
          hashtable_get_id(table, hkey));

  return NULL;
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
