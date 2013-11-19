/* ---------------------------------------------------------------------- */
/* Filename: exec.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-18 - 20:11:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "regions_table.h"
#include "error.h"
#include "exec.h"

/** Taille d'une pile à l'exécution. */
#define DATA_STACK_SIZE 65536

/** Obtenir une région. */
#define REGION_TABLE_GET(NUM) ((NUM == 0) ? region_table_get(n_regions - 1) : region_table_get(NUM - 1))

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Une donnée de la pile à l'execution. */
typedef union
{
  int i;
  float f;
  char c; 
  char *s;
} Data;
  
/** Structure servant à récupérer le nombre de déclarations 
    de variables dans une région. */
typedef struct N_symbols
{
  int n;      /* Nombre de déclarations de variables. */
  int region; /* Numéro de la région. */
} N_symbols;

/** Structure servant à récupérer les déclarations de variables 
    d'une région. */
typedef struct A_symbols
{
  Symbol **array; /* Tableaux de déclarations de variables. */
  int region;     /* Numéro de la région. */
} A_symbols;
 
/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Nombre de régions. */
static int n_regions;

/* La variable sym est simple d'utilisation une fois initialisée : 
   sym[numero_region][num_declaration] => Pointeur sur la déclaration dans
   la table des déclarations. Cela permet à un appel de fonction/procedure
   de remplir facilement la pile à l'execution sans fouiller
   dans la table des déclarations. */
static Symbol ***sym;

/** Pile à l'exécution. */
static Data *data_stack;

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/* Important : Les déclaration évoquées dans les fonctions suivantes ne concernent 
   que les déclarations de variables. */

/** Compte le nombre de variables de même nom à partir d'une déclaration donnée. */
/* %param value : Déclaration de départ. */
/* %param cvalue : Compteur de type N_symbols. */
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

/** Définir le déplacement à l'execution des variables du tableau de tableau sym. */
static void exec_set_variables_move(void);

/* ---------------------------------------------------------------------- */

static void exec_count_variables_ap(void *value, void *cvalue)
{
  Symbol *s = value;
  N_symbols *n = cvalue;

  for(; s != NULL; s = s->next) 
    if(s->type == SYMBOL_TYPE_VAR && s->region == n->region)
      n->n++;

  return;
}

static int exec_count_variables(Symbol_table *table, int region)
{
  N_symbols n;
  
  n.n = 0;
  n.region = region;
  hashtable_foreach_value(table, exec_count_variables_ap, &n);
  
  return n.n;
}

static void exec_get_variables_ap(void *value, void *cvalue)
{
  Symbol *s = value;
  A_symbols *a = cvalue;

  for(; s != NULL; s = s->next) 
    if(s->type == SYMBOL_TYPE_VAR && s->region == a->region)
    {
      *(a->array) = s;
      a->array++;
    }

  return;
}

static Symbol **exec_get_variables(Symbol_table *table, int region)
{
  int n = exec_count_variables(table, region);
  Symbol **sym = malloc((n + 1) * sizeof *sym); 
  A_symbols a;

  a.region = region;
  a.array = sym;

  if(sym == NULL)
    fatal_error("exec_get_variables");

  hashtable_foreach_value(table, exec_get_variables_ap, &a);
  sym[n] = NULL; /* Dernier élément du tableau. */

  return sym;
}

static void exec_set_variables_move(void)
{
  int i, j;
  Region *region;

  for(i = 0; i < n_regions; i++)
    if(sym[i][0] != NULL)
    { 
      region = REGION_TABLE_GET(i);

      /* Première déclaration liée au Niveau d'Imbrication Statique de la région. */
      sym[i][0]->exec = (region->level == 0) ? 0 : region->level + 1;

      /* Le déplacement à l'execution d'une variable est égale à :
	 La position de la variable précédente + la taille du type 
	 de la variable précédente. */
      for(j = 1; sym[i][j] != NULL; j++)
	sym[i][j]->exec += sym[i][j - 1]->exec + ((Symbol *)sym[i][j - 1]->index)->exec;

      /* Taille de la région courante : 
	 Déplacement à l'exec de la dernière variable ajoutée + sa taille. */
      j--;
      region->size = sym[i][j]->exec + ((Symbol *)sym[i][j]->index)->exec;
    }
    else
      region->size = region->level;
}

/* ---------------------------------------------------------------------- */

Data region_eval(int region)
{
  Region *data_region = region_table_get(region);
  Data result;

  if(data_region == NULL)
  {
    fprintf(stderr, "Region = %d\n", region);
    fatal_error("Unable to find the region !");
  }
 
  regions_table_print();

  
}

void exec(Symbol_table *table)
{
  /* Initialisation. */

  int i;
  
  if((n_regions = regions_table_get_size()) == 0)
    return;

  if((sym = malloc(n_regions * sizeof *sym)) == NULL)
    fatal_error("exec");

  for(i = 0; i < n_regions; i++)
    sym[i] = exec_get_variables(table, i - 1);

  exec_set_variables_move();

  if((data_stack = malloc(DATA_STACK_SIZE * sizeof *data_stack)) == NULL)
    fatal_error("exec");

  /* Execution. */
  /* Nota : La dernière région ajoutée est la région principale d'où n_regions - 1 */
  region_eval(n_regions - 1);

  /* Libération. */
  for(i = 0; i < n_regions; i++)
    free(sym[i]);
  
  free(sym);
  free(data_stack);

  return;
}
