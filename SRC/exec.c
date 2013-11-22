/* ---------------------------------------------------------------------- */
/* Filename: exec.c                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-18 - 20:11:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <setjmp.h>
#include "list.h"
#include "regions_table.h"
#include "error.h"
#include "exec.h"

/** Taille d'une pile à l'exécution. */
#define DATA_STACK_SIZE 65536

/** Obtenir une région. */
#define REGION_TABLE_GET(NUM) ((NUM == 0) ? region_table_get(n_regions - 1) : region_table_get(NUM - 1))

/** Retourne la région d'un noeud de type variable. */
#define VARIABLE_REGION(VAR) ((Symbol *)syntax_tree_node_get_content(VAR)->value.var.type)->region

/** Retourne le lexeme d'un noeud de type variable. */
#define VARIABLE_LEXEME(VAR) lexeme_table_get(hashtable, syntax_tree_node_get_content(VAR)->value.var.hkey)

/** Affichage d'une valeur de la pile. */
#define VARIABLE_PRINT(STREAM, STACK_VAR)       \
  switch(STACK_VAR.type)                        \
  {                                             \
    case SYMBOL_BASIC_INT:                      \
      fprintf(STREAM, "%d", STACK_VAR.value.i); \
      break;                                    \
    case SYMBOL_BASIC_FLOAT:                    \
      fprintf(STREAM, "%f", STACK_VAR.value.f); \
      break;                                    \
    case SYMBOL_BASIC_BOOL:                     \
      (STACK_VAR.value.c) ?                     \
        fprintf(STREAM, "true") :               \
        fprintf(STREAM, "false");               \
        break;                                  \
    case SYMBOL_BASIC_CHAR:                     \
      fprintf(STREAM, "%c", STACK_VAR.value.c); \
      break;                                    \
    case SYMBOL_BASIC_STRING:                   \
      fprintf(STREAM, "%s", STACK_VAR.value.s); \
      break;                                    \
  }

/** Debug d'une affectation. */
#ifdef DEBUG
  #define DBG_SET(TREE)                                                                  \
    do {                                                                                 \
      DBG_PRINTF(("Region %d : %s=", VARIABLE_REGION((TREE)), VARIABLE_LEXEME((TREE)))); \
      VARIABLE_PRINT(stderr, result);                                                    \
      fprintf(stderr, "\n");                                                             \
    } while(0)
#else
  #define DBG_SET(TREE)
#endif

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

extern Hashtable *hashtable;

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

/** Saut. Utilisé en cas de dépassement de pile. */
static jmp_buf jmp;

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

/** Met à 0 les données de la région courante. */
static void reset_stack(void);

/** Déplace la position dans la pile.
    Met à jour le chainage dynamique et statique. */
/* %param n : Numéro de région à ajouter sur la pile. */
/* %return : Le résultat de l'appel de fonction/procédure. */
static Data push_position(int n);

/** Evalue un arbre. */
/* %param tree : Arbre à évaluer. */
/* %return : Le résultat de l'évaluation. */
static Data region_eval(Syntax_tree *tree);

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

static void reset_stack(void)
{
  Region *region = REGION_TABLE_GET(current_region + 1);
  int i, num;
    
  i = !(region->level == 0); 

  for(i += region->level; i < region->size; i++)
  {
    num = i + stack_position;
    memset(&data_stack[num], 0, sizeof(Data));
    data_stack[num].type = SYMBOL_BASIC_CHAR;    
  }
   
  return;
}

static Data push_position(int n)
{
  Region *n_region = REGION_TABLE_GET(n);                  /* Nouvelle région. */
  Region *o_region = REGION_TABLE_GET(current_region + 1); /* Ancienne région. */
  Data result;
  int old_region = current_region;
  int i;

  DBG_PRINTF(("Ajout de la région: %d\n", n - 1));
  DBG_PRINTF(("Déplacement de la base courante de %lu\n", (unsigned long int)o_region->size));

  /* En cas de dépassement de pile. */
  if(stack_position + o_region->size + 1 + n_region->level >= DATA_STACK_SIZE)
  {    
    fprintf(stderr, "Error : Stack overflow !\n");
    longjmp(jmp, 1); /* Retour au début du programme. */
  }

  /* Mise à jour du chainage dynamique. */
  data_stack[stack_position + o_region->size].value.i = stack_position; 
  DBG_PRINTF(("Chainage dynamique: data_stack[%d] = %d\n", stack_position + o_region->size, 
              stack_position));

  /* Déplacement dans la pile de la taille de l'ancienne région. */                   
  stack_position += o_region->size;                 

  /* Mise à jour du chainage statique. */
  if(n_region->level > o_region->level)
  {
    data_stack[stack_position + 1].value.i = data_stack[stack_position].value.i; 
    DBG_PRINTF(("Chainage statique: data_stack[%d] = %d\n", stack_position + 1, 
                data_stack[stack_position].value.i));

    for(i = 2; i <= n_region->level; i++)
    {
      data_stack[stack_position + i].value.i = data_stack[stack_position - o_region->size + i - 1].value.i;
      DBG_PRINTF(("Chainage statique: data_stack[%d] = %d\n", stack_position + i, 
                  data_stack[stack_position + i].value.i));
    }
  }
  else
    for(i = 1; i <= n_region->level; i++)
    {
      data_stack[stack_position + i].value.i = 
        data_stack[stack_position - o_region->size + i + o_region->level - n_region->level].value.i;
 
      DBG_PRINTF(("Chainage statique: data_stack[%d] = %d\n", stack_position + i, 
                  data_stack[stack_position + i].value.i));
    }

  DBG_PRINTF(("%d case(s) de données\n\n", n_region->size - n_region->level * 2));

  /* Nouvelle région. */                          
  current_region = n - 1;

  /* Mise à 0 des valeurs de la nouvelle région. */
  reset_stack();

  /* Traitement de la région. */
  result = region_eval(n_region->tree);

  /* Reset de la région. */
  DBG_PRINTF(("Depilement de la région %d.\nRégion courante = %d\n", current_region, old_region));
  current_region = old_region;

  return result;
}

static size_t get_variable_position(Syntax_tree *tree)
{
  Syntax_node_content *content;
  Syntax_tree *current;
  Symbol *sym;
  unsigned int i;
  Structure *structure;
  Array *array;
  bool root = true;
  size_t size, size_base;
  Data result;

  /* Récupération du contenu de l'arbre. */
  content = syntax_tree_node_get_content(tree);
                              
  /* Ligne de déclaration du type de l'IDF. */
  sym = content->value.var.type;

  /* Champ de la variable. */
  if((i = current_region - sym->region) != 0)
    i = data_stack[i + 1].value.i;
  else
    i = stack_position;

  size = i + sym->exec; 

  /* Récupération du type de la variable. */
  sym = sym->index;
  
  for(;;)
  { 
    /* Parcours des champs. */
    switch(sym->type)
    {
      /* ------------------------------------------ */
      /* TYPE BASE                                  */
      /* ------------------------------------------ */
      
      case SYMBOL_TYPE_BASE:
      {
        /* Définition du type de la valeur. */
        for(i = 1; i <= SYMBOL_BASIC_MAX; i++)
          if(symbol_table_get_basic(i) == sym)
          {
            data_stack[size].type = i;
            break;
          }

        return size;
      }
 
      /* ------------------------------------------ */
      /* TYPE STRUCTURE                             */
      /* ------------------------------------------ */
        
      case SYMBOL_TYPE_STRUCT:
        if((root && (current = tree_node_get_son(tree)) == NULL) || 
           (!root && (current = tree_node_get_brother(tree)) == NULL))
          return size;
        
        /* Champ à utiliser. */
        content = syntax_tree_node_get_content(current);
        structure = sym->index;

        /* Mise a jour de la déclaration, arbre et taille. */
        sym = structure->field[content->value.i].type;
        tree = current;
        size += structure->exec[content->value.i];

        break;
 
      /* ------------------------------------------ */
      /* TYPE TABLEAU                               */
      /* ------------------------------------------ */

      case SYMBOL_TYPE_ARRAY:
        if((root && (current = tree_node_get_son(tree)) == NULL) || 
           (!root && (current = tree_node_get_brother(tree)) == NULL))
          return size;

        /* Recherche dans le prochain champ du tableau. */
        content = syntax_tree_node_get_content(current);
        array = sym->index;
        size_base = sym->exec;

        /* Déplacement dans le tableau. */
        for(i = 0; i < array->dimension_number; i++)
        {
          /* Calcul du déplacement de l'indicage courant. */
          size_base /= array->dimension[i].bound_upper - array->dimension[i].bound_lower;
          content = syntax_tree_node_get_content(current);

          /* Indicage de la case du tableau. */
          result = region_eval(tree_node_get_son(current));
          CAST(result, SYMBOL_BASIC_INT);

          /* Mauvais indicage. */
          if(result.value.i < array->dimension[i].bound_lower ||
             result.value.i >= array->dimension[i].bound_upper)
          {
            fprintf(stderr, "Exception : Index array is outside the limits!\n");
            longjmp(jmp, 1);
          } 
          
          /* Mise à 0 de l'indicage si besoin. */
          result.value.i -= array->dimension[i].bound_lower;

          /* Ajout du déplacement de l'indicage dans la taille courante. */
          size += result.value.i * size_base * ((Symbol *)array->type)->exec;

          if(tree_node_get_brother(current) == NULL)
            break;

          current = tree_node_get_brother(current);        
        }

        sym = array->type;
        tree = current;
        break;
               
      /* ------------------------------------------ */
      /* DEFAULT                                    */
      /* ------------------------------------------ */

      default:
        break;
    }

    root = false;
  } 
  
  return 0;
}
             
static Data region_eval(Syntax_tree *tree)
{
  Data result;
  Syntax_node_content *content;
  Syntax_tree *son;
  Data res_a, res_b;
  size_t size;

  memset(&result, 0, sizeof(Data));
  result.type = SYMBOL_BASIC_CHAR;

  if(tree == NULL)
    return result;

  content = syntax_tree_node_get_content(tree);

  switch(content->type)
  {
    /* ------------------------------------------ */
    /* OPERATIONS                                 */
    /* ------------------------------------------ */

    case AT_OP_PLUS:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_ADD(result, res_a, res_b); /* result = res_a + res_b */
      break;

    case AT_OP_MINUS:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_SUB(result, res_a, res_b); /* result = res_a - res_b */
      break;

    case AT_OP_MULT:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_MUL(result, res_a, res_b); /* result = res_a * res_b */
      break;

    case AT_OP_DIV:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_DIV(result, res_a, res_b); /* result = res_a / res_b */
      break;

    case AT_OP_MOD:
      res_a = region_eval(tree_node_get_son(tree));
      res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree)));
      OP_SET_TYPE(res_a, res_b);
      OP_MOD(result, res_a, res_b); /* result = res_a % res_b */
      break;
      
    /* ------------------------------------------ */
    /* AFFECTATIONS                               */
    /* ------------------------------------------ */

    case AT_EQUAL:
      son = tree_node_get_son(tree);                    /* Variable.    */
      size = get_variable_position(son);                /* Déplacement. */
      result = region_eval(tree_node_get_brother(son)); /* Valeur d'affectation. */
      CAST(result, data_stack[size].type);

      /* Affectation. */
      data_stack[size] = result;                        
      DBG_SET(son);
      break;

    case AT_OPR_PLUSE:
      son = tree_node_get_son(tree);                   /* Variable.    */
      size = get_variable_position(son);               /* Déplacement. */
     
      res_a = data_stack[size];                        /* Valeur de la variable. */
      res_b = region_eval(tree_node_get_brother(son)); /* Valeur à droite de la variable. */

      /* Opération += */
      OP_SET_TYPE(res_a, res_b);
      OP_ADD(result, res_a, res_b); /* += */
      CAST(result, data_stack[size].type);

       /* Affectation. */
      data_stack[size] = result; 
      DBG_SET(son);
      break;

    case AT_OPR_MINE:
      son = tree_node_get_son(tree);                   /* Variable.    */
      size = get_variable_position(son);               /* Déplacement. */
     
      res_a = data_stack[size];                        /* Valeur de la variable. */
      res_b = region_eval(tree_node_get_brother(son)); /* Valeur à droite de la variable. */

      /* Opération -= */
      OP_SET_TYPE(res_a, res_b);
      OP_SUB(result, res_a, res_b); /* -= */
      CAST(result, data_stack[size].type);

       /* Affectation. */
      data_stack[size] = result; 
      DBG_SET(son);
      break;

    case AT_OPR_MULTE:
      son = tree_node_get_son(tree);                   /* Variable.    */
      size = get_variable_position(son);               /* Déplacement. */
     
      res_a = data_stack[size];                        /* Valeur de la variable. */
      res_b = region_eval(tree_node_get_brother(son)); /* Valeur à droite de la variable. */

      /* Opération *= */
      OP_SET_TYPE(res_a, res_b);
      OP_MUL(result, res_a, res_b); /* *= */
      CAST(result, data_stack[size].type);

       /* Affectation. */
      data_stack[size] = result; 
      DBG_SET(son);
      break;

    case AT_OPR_DIVE:
      son = tree_node_get_son(tree);                   /* Variable.    */
      size = get_variable_position(son);               /* Déplacement. */
     
      res_a = data_stack[size];                        /* Valeur de la variable. */
      res_b = region_eval(tree_node_get_brother(son)); /* Valeur à droite de la variable. */

      /* Opération /= */
      OP_SET_TYPE(res_a, res_b);
      OP_DIV(result, res_a, res_b); /* /= */
      CAST(result, data_stack[size].type);

       /* Affectation. */
      data_stack[size] = result; 
      DBG_SET(son);
      break;

    case AT_OPR_MODE:
      son = tree_node_get_son(tree);                   /* Variable.    */
      size = get_variable_position(son);               /* Déplacement. */
     
      res_a = data_stack[size];                        /* Valeur de la variable. */
      res_b = region_eval(tree_node_get_brother(son)); /* Valeur à droite de la variable. */

      /* Opération %= */
      OP_SET_TYPE(res_a, res_b);
      OP_MOD(result, res_a, res_b); /* %= */
      CAST(result, data_stack[size].type);

       /* Affectation. */
      data_stack[size] = result; 
      DBG_SET(son);
      break;

    /* ------------------------------------------ */
    /* INCREMENTATIONS/DECREMENTATIONS            */
    /* ------------------------------------------ */
    
    case AT_OB_INC:
      break;
    case AT_OB_DEC:
      break;
    case AT_OB_PINC:
      break;
    case AT_OB_PDEC:
      break;

    /* ------------------------------------------ */
    /* COMPARAISONS                               */
    /* ------------------------------------------ */

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

    case AT_VAR:
      result = data_stack[get_variable_position(tree)];
      break;

    /* Appel de fonction/procédure. */
    case AT_CTL_CALL:
      result = push_position(((Symbol *)content->value.var.type)->exec + 1);
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
    case AT_ARRAY_INDEX:
    case AT_HKEY_INDEX:
      break;
  }

  return result;
}

/* ---------------------------------------------------------------------- */

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

  if((data_stack = calloc(DATA_STACK_SIZE, sizeof *data_stack)) == NULL)
    fatal_error("exec");

  /* Execution. */
  current_region = -1;
  region = REGION_TABLE_GET(0);
  reset_stack();

  if(!setjmp(jmp)) 
    region_eval(region->tree);
  /* Dépassement de pile. */
  else 
  {

  }

  /* Libération. */
  for(i = 0; i < n_regions; i++)
    free(sym[i]);
  
  free(sym);
  free(data_stack);

  return;
}

