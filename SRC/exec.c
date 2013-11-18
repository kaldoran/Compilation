/* ---------------------------------------------------------------------- */
/* Filename: exec.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-18 - 20:11:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "regions_table.h"
#include "error.h"
#include "exec.h"

/** Taille d'une pile à l'exécution. */
#define DATA_STACK_SIZE 65536

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Une donnée de la pile à l'execution. */
typedef union
{
  int i;
  float f;
  char c; 
} Data;
  
/** Pile à l'execution. */
Data *stack;

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/* Important : Les déclaration évoquées dans les fonctions suivantes ne concernent 
   que les déclarations de variables. */

/** Compte le nombre de variables de même nom à partir d'une déclaration donnée. */
/* %param value : Déclaration de départ. */
/* %param cvalue : Compteur de type int*. */
static void exec_count_variables_ap(void *value, void *cvalue);

/** Obtenir le nombre de déclarations de variables pour une région donnée. */
/* %param table : Table des déclarations. */
/* %param region : Numéro de la région. */
/* %return : Nombre de déclarations de variables pour une région donnée. */
static int exec_count_variables(Symbol_table *table, int region);

/** Remplir un tableau de déclarations à partir d'une déclaration donnée. */
/* %param value : Déclaration de départ. */
/* %param cvalue : Tableau suffisament grand pour contenir les déclarations. */
static void exec_get_variables_ap(void *value, void *cvalue);

/** Obtenir un tableau de toutes les déclarations de variables d'une région. */
/* %param table : Table des déclarations. */
/* %param region : Numéro de la région. */
/* %return : Tableau de déclarations d'une région. Le dernier élément vaut NULL. */
static Symbol **exec_get_variables(Symbol_table *table, int region);

/* ---------------------------------------------------------------------- */

static void exec_count_variables_ap(void *value, void *cvalue)
{
  Symbol *s = value;
  
  for(; s != NULL; s = s->next) 
    if(s->type == SYMBOL_TYPE_VAR)
      *(int *)cvalue += 1;

  return;
}

static int exec_count_variables(Symbol_table *table, int region)
{
  int n = 0;
  hashtable_foreach_value(table, exec_count_variables_ap, &n);
  return n;
}

static void exec_get_variables_ap(void *value, void *cvalue)
{
  Symbol *s = value;
  Symbol **array = cvalue;

  for(; s != NULL; s = s->next) 
    if(s->type == SYMBOL_TYPE_VAR)
    {
      *array = s;
      array++;
    }

  return;
}

static Symbol **exec_get_variables(Symbol_table *table, int region)
{
  int n = exec_count_variables(table, region);
  Symbol **sym = malloc((n + 1) * sizeof *sym); 
  
  if(sym == NULL)
    fatal_error("exec_get_variables");

  hashtable_foreach_value(table, exec_get_variables_ap, sym);
  sym[n] = NULL; /* Dernier élément du tableau. */

  return sym;
}

/* ---------------------------------------------------------------------- */

void exec(Symbol_table *table)
{
  /* La variable sym est simple d'utilisation une fois initialisée : 
     sym[numero_region][num_declaration] => Pointeur sur la déclaration dans
     la table des déclarations. Cela permet à un appel de fonction/procedure
     de remplir facilement la pile à l'execution sans fouiller
     dans la table des déclarations. */

  /* Initialisation. */

  int i;
  int n_regions = regions_table_get_size();
  Symbol ***sym = malloc(n_regions * sizeof *sym);

  if(sym == NULL)
    fatal_error("exec");

  for(i = 0; i < n_regions; i++)
    sym[i] = exec_get_variables(table, i - 1);

  /* Execution. */



  /* Libération. */
  for(i = 0; i < n_regions; i++)
    free(sym[i]);
  
  free(sym);

  return;
}
