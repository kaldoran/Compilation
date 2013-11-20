/* ---------------------------------------------------------------------- */
/* Filename: exec.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-18 - 20:11:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "regions_table.h"
#include "error.h"
#include "exec.h"

/** Taille d'une pile à l'exécution. */
#define DATA_STACK_SIZE 65536

/** Obtenir une région. */
#define REGION_TABLE_GET(NUM) ((NUM == 0) ? region_table_get(n_regions - 1) : region_table_get(NUM - 1))

#include "exec_cast.h"
#include "exec_op.h"

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Une valeur de donnée de la pile à l'execution. */
typedef union
{
  int i;   /* Un entier. */
  float f; /* Un flottant. */
  char c;  /* Un caractère. */
  char *s; /* Une chaine. */
} Value;
  
/** Une donnée de la pile à l'execution. */
typedef struct Data
{
  char type;   /* Type de la donnée. */
  Value value; /* Valeur de la donnée. */
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

/** Région courante. (Son numéro et non son indice dans la table des régions) */
static int current_region = -1;

/** Pile à l'exécution. */
static Data *data_stack;

/** Position dans la pile à l'exécution. */
static unsigned int stack_position = 0;

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

Data region_eval(Syntax_tree *tree);

/** Déplace la position dans la pile. */
void push_position(int n)
{
  Region *n_region = REGION_TABLE_GET(n);                  /* Nouvelle région. */
  Region *o_region = REGION_TABLE_GET(current_region + 1); /* Ancienne région. */
  int old_region = current_region;
  int i;

  /* Déplacement dans la pile de la taille de l'ancienne région. */                   
  stack_position += o_region->size;                 
  
  /* Mise à jour du chainage dynamique. */
  data_stack[stack_position].value.i = current_region; 
  
  /* Mise à jour du chainage statique. */

  /* Nouvelle région. */                          
  current_region = n - 1;

  /* Traitement de la région. */
  region_eval(n_region->tree);

  /* Reset de la région. */
  current_region = old_region;

  return;
}

Data region_eval(Syntax_tree *tree)
{
  Data result;
  Syntax_node_content *content; 
  Data res_a, res_b;

  result.value.i = 0;

  if(tree == NULL)
  {
    fprintf(stderr, "Attention : Empty node !\n");
    return result;
  }

  content = syntax_tree_node_get_content(tree);

  switch(content->type)
  {
    /* Opérations. */
    case AT_OP_PLUS:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_ADD(result, res_a, res_b);
      break;
    case AT_OP_MINUS:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_SUB(result, res_a, res_b);
      break;
    case AT_OP_MULT:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_MUL(result, res_a, res_b);
      break;
    case AT_OP_DIV:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_DIV(result, res_a, res_b);
      break;
    case AT_OP_MOD:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_MOD(result, res_a, res_b);
      break;

    /* Affectations. */
    case AT_EQUAL:
      break;
    case AT_OPR_PLUSE: 
      break;
    case AT_OPR_MINE:
      break;
    case AT_OPR_MULTE:
      break;
    case AT_OPR_DIVE:
      break;
    case AT_OPR_MODE:
      break;

    /* Incrémentations/Décrémentations. */
    case AT_OB_INC:
      break;
    case AT_OB_DEC:
      break;
    case AT_OB_PINC:
      break;
    case AT_OB_PDEC:
      break;

    /* Comparaisons. */
    case AT_CMP_E:
      break;
    case AT_CMP_G:
      break;
    case AT_CMP_GE:
      break;
    case AT_CMP_L:
      break;
    case AT_CMP_LE:
      break;
    case AT_CMP_NE:
      break;

    /* Conditions. */
    case AT_CND_AND:
      break;
    case AT_CND_OR:
      break;
    case AT_CND_NOT:
      break;

    /* Fonctions prédéfinies. */
    case AT_FUN_READ:
      break;
    case AT_FUN_WRITE:
      break;
    case AT_FUN_RAND:
      break;

    /* Contrôles. */
    case AT_CTL_IF:   
      break;
    case AT_CTL_ELSE:
    case AT_CTL_WHILE:  
    case AT_CTL_DO_WHILE: 
    case AT_CTL_FOR:
  
    case AT_CTL_RETURN:
    case AT_CTL_SWITCH:
    case AT_CTL_CASE:
    case AT_CTL_DEFAULT:
    case AT_CTL_BREAK:
    case AT_CTL_CONTINUE:
    case AT_CTL_TERNAIRE:
      break;


    case AT_VAR       :
    case AT_ARRAY_INDEX :
    case AT_HKEY_INDEX  :
      break;

    /* Appel de fonction/procédure. */
    case AT_CTL_CALL:
      push_position(((Symbol *)content->value.var.type)->exec + 1);
      break;
      
    /* Constantes. */
    case AT_CST_STRING: 
      result.value.s = content->value.s;
      result.type = SYMBOL_BASIC_STRING;
      break;
    case AT_CST_FLOAT:
      result.value.f = content->value.f;
      result.type = SYMBOL_BASIC_FLOAT;
      break;
    case AT_CST_BOOL:
      result.value.c = content->value.c;
      result.type = SYMBOL_BASIC_BOOL;
      break;
    case AT_CST_CHAR: 
      result.value.c = content->value.c;
      result.type = SYMBOL_BASIC_CHAR;
      break;
    case AT_CST_INT:
      result.value.i = content->value.i;
      result.type = SYMBOL_BASIC_INT;
      break;

    /* Noeud vide. */
    case AT_EMPTY:
      break;

    /* Non-utilisés. */
    case AT_CTL_ARRAY:    
    case AT_CTL_STRUCT: 
    case AT_CTL_PROC:
    case AT_CTL_FUN:
      break;
  }

  return result;
}

void exec(Symbol_table *table)
{
  /* Initialisation. */

  int i;
  Region *region;

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
  current_region = -1;
  region = REGION_TABLE_GET(0);
  region_eval(region->tree);

  /* Libération. */
  for(i = 0; i < n_regions; i++)
    free(sym[i]);
  
  free(sym);
  free(data_stack);

  return;
}
