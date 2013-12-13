/* ---------------------------------------------------------------------- */
/* Filename: exec.c                                                       */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-11-18 - 20:11:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
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

/** Met à 0 la valeur d'une variable. */
#define VARIABLE_RESET(STACK_VAR)        \
  do {                                   \
    memset(&STACK_VAR, 0, sizeof(Data)); \
    STACK_VAR.type = SYMBOL_BASIC_CHAR;  \
} while(0)

/** Affichage d'une valeur de la pile. */
#define VARIABLE_PRINT(STREAM, STACK_VAR)         \
  switch(STACK_VAR.type)                          \
  {                                               \
    case SYMBOL_BASIC_INT:                        \
      fprintf(STREAM, "%d", STACK_VAR.value.i);   \
      break;                                      \
    case SYMBOL_BASIC_FLOAT:                      \
      fprintf(STREAM, "%f", STACK_VAR.value.f);   \
      break;                                      \
    case SYMBOL_BASIC_BOOL:                       \
      (STACK_VAR.value.c) ?                       \
        fprintf(STREAM, "true") :                 \
        fprintf(STREAM, "false");                 \
      break;                                      \
    case SYMBOL_BASIC_CHAR:                       \
      fprintf(STREAM, "'%c'", STACK_VAR.value.c); \
      break;                                      \
    case SYMBOL_BASIC_STRING:                     \
      if(STACK_VAR.value.s != NULL)               \
        fprintf(STREAM, "%s", STACK_VAR.value.s); \
      break;                                      \
    case SYMBOL_BASIC_STRING_UP:                  \
      if(STACK_VAR.value.s != NULL)               \
        fprintf(STREAM, "%s", STACK_VAR.value.s); \
      free(STACK_VAR.value.s);                    \
      break;                                      \
  }

/** Applique un calcul (+, -, /, *, %). */
/* Utilisée par chaque case AT_OP_... */
#define SET_OP(TYPE)                                                     \
  do {                                                                   \
    res_a = region_eval(tree_node_get_son(tree));                        \
    res_b = region_eval(tree_node_get_brother(tree_node_get_son(tree))); \
    OP_SET_TYPE(res_a, res_b);                                           \
    TYPE(result, res_a, res_b); /* result = res_a OP res_b */            \
  } while(0)

/** Applique une opération d'affectation (+=, -=, /=, *=, %=). */
/* Utilisée par chaque case AT_OPR_... */
#define SET_OPR(TYPE)                                \
  do {                                               \
    son = tree_node_get_son(tree);                   \
    size = get_variable_position(son);               \
                                                     \
    /* res_a = Valeur de la variable actuelle. */    \
    /* res_b = Valeur de la partie droite. */        \
    res_a = data_stack[size];                        \
    res_b = region_eval(tree_node_get_brother(son)); \
                                                     \
    /* Opération */                                  \
    OP_SET_TYPE(res_a, res_b);                       \
    TYPE(result, res_a, res_b);                      \
    CAST(result, data_stack[size].type);             \
                                                     \
    /* Affectation. */                               \
    data_stack[size] = result;                       \
    DBG_SET(son, size);                              \
  } while(0)

/** Applique une incrémentation/décrémentation. */
/* Utilisée par chaque case AT_OB_... */
#define SET_OB(VALUE)                                  \
    do {                                               \
      son = tree_node_get_son(tree);                   \
      size = get_variable_position(son);               \
                                                       \
      res_a.value.c = VALUE;                           \
      res_b = region_eval(son);                        \
                                                       \
      /* Inc/Dec */                                    \
      OP_SET_TYPE(res_a, res_b);                       \
      OP_ADD(result, res_a, res_b);                    \
      CAST(result, data_stack[size].type);             \
                                                       \
      data_stack[size] = result;                       \
      DBG_SET(son, size);                              \
} while(0)

/** Applique une comparaison. */
/* Utilisée par chaque case AT_CMP_... */
#define SET_CMP(CMP)                                                   \
    do {                                                               \
      son = tree_node_get_son(tree);                                   \
      res_a = region_eval(son);                                        \
      res_b = region_eval(tree_node_get_brother(son));                 \
      OP_SET_TYPE(res_a, res_b);                                       \
      result.type = SYMBOL_BASIC_BOOL;                                 \
                                                                       \
      switch(res_a.type)                                               \
      {                                                                \
        case SYMBOL_BASIC_INT:                                         \
          result.value.c = res_a.value.i CMP res_b.value.i;            \
          break;                                                       \
        case SYMBOL_BASIC_FLOAT:                                       \
          result.value.c = res_a.value.f CMP res_b.value.f;            \
          break;                                                       \
        case SYMBOL_BASIC_BOOL:                                        \
          result.value.c = res_a.value.c CMP res_b.value.c;            \
          break;                                                       \
        case SYMBOL_BASIC_CHAR:                                        \
          result.value.c = res_a.value.c CMP res_b.value.c;            \
          break;                                                       \
        case SYMBOL_BASIC_STRING:                                      \
        case SYMBOL_BASIC_STRING_UP:                                   \
          result.value.c = 0 CMP strcmp(res_a.value.s, res_b.value.s); \
                                                                       \
          if(res_a.type == SYMBOL_BASIC_STRING_UP)                     \
            free(res_a.value.s);                                       \
          if(res_b.type == SYMBOL_BASIC_STRING_UP)                     \
            free(res_b.value.s);                                       \
          break;                                                       \
      }                                                                \
    } while(0)

/** Evalue à la suite les instructions d'un arbre. */
#define EVAL_BROTHERS(TREE)                   \
  while(TREE != NULL && !return_state)        \
  {                                           \
    result = region_eval(TREE);               \
    TREE = tree_node_get_brother(TREE);       \
                                              \
    /* Si l'instruction retour enclenchée. */ \
    if(return_state)                          \
    {                                         \
      TREE = NULL;                            \
      break;                                  \
    }                                         \
  }

/** Copie correctement un résultat dans la pile. */
#define COPY_RESULT(SIZE, RES)                          \
  do {                                                  \
    if(RES.type == SYMBOL_BASIC_STRING)                 \
    {                                                   \
      free(data_stack[SIZE].value.s);                   \
                                                        \
      /* Copie d'une référence de chaine existente. */  \
      data_stack[SIZE].value.s = mystrdup(RES.value.s); \
    }                                                   \
    else if(RES.type == SYMBOL_BASIC_STRING_UP)         \
    {                                                   \
      /* Nouvelle chaine. */                            \
      RES.type = SYMBOL_BASIC_STRING;                   \
      data_stack[SIZE].value.s = RES.value.s;           \
    }                                                   \
    else                                                \
      data_stack[SIZE] = RES;                           \
  } while(0)

/** Debug d'une affectation. */
#ifdef DEBUG
  #define DBG_SET(TREE, SIZE)                                 \
    do {                                                      \
      DBG_PRINTF(("Region %d : %s=", VARIABLE_REGION((TREE)), \
                VARIABLE_LEXEME((TREE))));                    \
      VARIABLE_PRINT(stderr, result);                         \
      fprintf(stderr, " (stack[%lu])\n", SIZE);               \
    } while(0)
#else
  #define DBG_SET(TREE, SIZE)
#endif

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

/** Return activé ? */
static bool return_state = false;

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
/* %param tree : Noeud contenant la procédure/Fonction à appeler. */
/* %return : Le résultat de l'appel de fonction/procédure. */
static Data push_position(Syntax_tree *tree);

/** Evalue un arbre. */
/* %param tree : Arbre à évaluer. */
/* %return : Le résultat de l'évaluation. */
static Data region_eval(Syntax_tree *tree);

/** Fonction écrire. */
/* %param tree : Noeud de type AT_FUN_WRITE. */
void fun_write(Syntax_tree *tree);

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
  {
    region = REGION_TABLE_GET(i);

    if(sym[i][0] != NULL)
    {
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
      region->size = (region->level == 0) ? 0 : region->level + 1;
  }
}

/* ---------------------------------------------------------------------- */

static void reset_stack(void)
{
  Region *region = REGION_TABLE_GET(current_region + 1);
  int i, num;

  i = !(region->level == 0);

  for(i += region->level; i < region->size; i++)
  {
    num = i + stack_position;
    VARIABLE_RESET(data_stack[num]);
  }

  return;
}

static void clean_string(void)
{
  Region *region = REGION_TABLE_GET(current_region + 1);
  int i, num;

  i = !(region->level == 0);

  for(i += region->level; i < region->size; i++)
  {
    num = i + stack_position;

    if(data_stack[num].type == SYMBOL_BASIC_STRING)
      free(data_stack[num].value.s);
  }

  return;
}

static Data push_position(Syntax_tree *tree)
{
  Syntax_node_content *content = syntax_tree_node_get_content(tree); /* Contenu du noeud. */

  Symbol *sym = content->value.var.type; /* Champ de déclaration de la procédure/Fonction. */
  Symbol *sym_p;                         /* Champ de déclaration d'un paramètre. */
  int n = sym->exec + 1;                 /* Numéro de la région à ajouter sur la pile. */

  Region *n_region = REGION_TABLE_GET(n);                  /* Nouvelle région. */
  Region *o_region = REGION_TABLE_GET(current_region + 1); /* Ancienne région. */
  Data result;                                             /* Valeur de retour de la fonction/procédure. */
  Parameter *params;                                       /* Paramètres de la fonction/procédure. */

  /* Autres données. */
  int old_region = current_region;
  unsigned int i, j;

  /* Mise à 0 de la valeur de retour. */
  VARIABLE_RESET(result);

  DBG_PRINTF(("Ajout de la région: %d\n", n - 1));
  DBG_PRINTF(("Déplacement de la base courante de %lu\n", (unsigned long int)o_region->size));

  /* En cas de dépassement de pile. */
  if(stack_position + o_region->size + 1 + n_region->level >= DATA_STACK_SIZE)
  {
    fprintf(stderr, "Error : Stack overflow !\n");
    longjmp(jmp, 1);
  }

  /* Mise à jour du chainage dynamique. */
  data_stack[stack_position + o_region->size].value.i = stack_position;
  DBG_PRINTF(("Chainage dynamique: data_stack[%d] = %d\n", stack_position + o_region->size,
              stack_position));

  /* Déplacement dans la pile de la taille de l'ancienne région. */
  stack_position += o_region->size;

  /* Mise à jour du chainage statique. */

  /* Si la nouvelle région est plus imbriquée. */
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

  /* Région moins imbriquée. */
  else
    for(i = 1; i <= n_region->level; i++)
    {
      data_stack[stack_position + i].value.i =
        data_stack[stack_position - o_region->size + i + o_region->level - n_region->level].value.i;

      DBG_PRINTF(("Chainage statique: data_stack[%d] = %d\n", stack_position + i,
                  data_stack[stack_position + i].value.i));
    }

  DBG_PRINTF(("%d case(s) de données\n\n", n_region->size - n_region->level - 1));

  /* Nouvelle région. */
  current_region = n - 1;

  /* Mise à 0 des valeurs de la nouvelle région. */
  reset_stack();

  /* Ajout des paramètres de la procédure/fonction sur la pile. */
  if(sym->type == SYMBOL_TYPE_PROCEDURE)
    params = ((Procedure *)sym->index)->params;
  else
    params = ((Function *)sym->index)->params;

  tree = tree_node_get_son(tree);

  for(i = 0; tree != NULL; i++)
  {
    /* Déplacement necessaire en arrière pour évaluer les paramètres
       de régions. */

    stack_position -= o_region->size;
    current_region = old_region;

    result = region_eval(tree);

    stack_position += o_region->size;
    current_region = n - 1;

    /* Type du paramètre. */
    for(j = 1; j <= SYMBOL_BASIC_MAX; j++)
      if(symbol_table_get_basic(j) == params[i].type)
        break;

    /* Valeur du paramètre. */
    CAST(result, j);

    /* Affectation. */
    sym_p = hashtable_get_value_by_key(hashtable, params[i].hkey);

    for(; sym_p->region != current_region; sym_p = sym_p->next);
    COPY_RESULT(stack_position + sym_p->exec, result);

    /* Paramètre suivant. */
    tree = tree_node_get_brother(tree);
  }

  /* Traitement de la région. */
  tree = n_region->tree;
  EVAL_BROTHERS(tree);

  /* Valeur de retour de la procédure/fonction. */
  if(sym->type == SYMBOL_TYPE_PROCEDURE)
    VARIABLE_RESET(result);
  else
    CAST(result, ((Symbol *)((Function *)sym->index)->return_type)->type);

  /* Reset de la région et nettoyage des chaines. */
  DBG_PRINTF(("Depilement de la région %d.\nRégion courante = %d\n", current_region, old_region));
  clean_string();
  current_region = old_region;
  return_state = false;
  stack_position -= o_region->size;

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
  bool prev = false;
  Region *region_1;
  Region *region_2;

  /* Récupération du contenu de l'arbre. */
  content = syntax_tree_node_get_content(tree);

  /* Ligne de déclaration du type de l'IDF. */
  sym = content->value.var.type;

  /* Champ de la variable. */
  region_1 = REGION_TABLE_GET(current_region + 1);
  region_2 = REGION_TABLE_GET(sym->region + 1);

  i = region_1->level - region_2->level;

  /* Niveau -1 et récursivité. */
  if(region_1->level == 0 || region_1 == region_2)
    i = stack_position;
  /* Chainage statique. */
  else if(i > 0)
    i = data_stack[stack_position + i].value.i;

  /* Cas théoriquement impossibles. */
  else if(i == 0)
  {
    fprintf(stderr, "Les alcooliques chevaucheront des brosses à dents.\n");
    exit(EXIT_FAILURE);
  }
  else if(i < 0)
  {
    fprintf(stderr, "Un ingénieur informaticien effraiera ces commères.\n");
    exit(EXIT_FAILURE);
  }

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

        /* En théorie, ne peut arriver.
           Enfin seulement si symbol_table_init_by_load(Symbol_table *table)
           n'est pas appelée après un chargement de fichier compilé. */
        if(i > SYMBOL_BASIC_MAX)
        {
          fprintf(stderr, "Marie Curie greffe la science aux fumistes !\n");
          exit(EXIT_FAILURE);
        }

        return size;
      }

      /* ------------------------------------------ */
      /* TYPE STRUCTURE                             */
      /* ------------------------------------------ */

      case SYMBOL_TYPE_STRUCT:
        if((root && (current = tree_node_get_son(tree)) == NULL) || (!root && (current = tree_node_get_brother(tree)) == NULL) || prev)
        {
          structure = sym->index;
          content = syntax_tree_node_get_content(tree);
          size += structure->exec[content->value.i];
          sym = structure->field[content->value.i].type;
          prev = false;
          break;
        }

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
        if((root && (current = tree_node_get_son(tree)) == NULL) || (!root && (current = tree_node_get_brother(tree)) == NULL))
        {
          /* Erreur : normalement impossible. */
          fprintf(stderr, "Des filles bifurquaient en salle informatique.\n");
          exit(EXIT_FAILURE);
        }

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
          size += result.value.i * size_base;

          if(tree_node_get_brother(current) == NULL)
            break;

          current = tree_node_get_brother(current);
        }

        sym = array->type;
        tree = current;
        prev = true;

        break;

      /* ------------------------------------------ */
      /* DEFAULT                                    */
      /* ------------------------------------------ */

      default:
        break;
    } /* Fin switch. */

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

  /* Mise à 0 des variables. */
  VARIABLE_RESET(result);
  VARIABLE_RESET(res_a);
  VARIABLE_RESET(res_b);

  if(tree == NULL)
    return result;

  content = syntax_tree_node_get_content(tree);

  switch(content->type)
  {
    /* ------------------------------------------ */
    /* OPERATIONS                                 */
    /* ------------------------------------------ */

    case AT_OP_PLUS:
      SET_OP(OP_ADD);
      break;
    case AT_OP_MINUS:
      SET_OP(OP_SUB);
      break;
    case AT_OP_MULT:
      SET_OP(OP_MUL);
      break;
    case AT_OP_DIV:
      SET_OP(OP_DIV);
      break;
    case AT_OP_MOD:
      SET_OP(OP_MOD);
      break;

      /* ------------------------------------------ */
      /* AFFECTATIONS                               */
      /* ------------------------------------------ */

    case AT_EQUAL:
      son = tree_node_get_son(tree);                    /* Variable.    */
      size = get_variable_position(son);                /* Déplacement. */
      result = region_eval(tree_node_get_brother(son)); /* Valeur d'affectation. */
      CAST(result, data_stack[size].type);
      COPY_RESULT(size, result);
      DBG_SET(son, size);
      break;

    case AT_OPR_PLUSE:
      SET_OPR(OP_ADD);
      break;
    case AT_OPR_MINE:
      SET_OPR(OP_SUB);
      break;
    case AT_OPR_MULTE:
      SET_OPR(OP_MUL);
      break;
    case AT_OPR_DIVE:
      SET_OPR(OP_DIV);
      break;
    case AT_OPR_MODE:
      SET_OPR(OP_MOD);
      break;

      /* ------------------------------------------ */
      /* INCREMENTATIONS/DECREMENTATIONS            */
      /* ------------------------------------------ */

    case AT_OB_PINC:
      SET_OB(1);
      break;
    case AT_OB_PDEC:
      SET_OB(-1);
      break;
    case AT_OB_INC:
      SET_OB(1);
      result = res_b; /* Valeur de la variable avant son incrémentation. */
      break;
    case AT_OB_DEC:
      SET_OB(-1);
      result = res_b; /* Valeur de la variable avant sa décrémentation. */
      break;

      /* ------------------------------------------ */
      /* COMPARAISONS                               */
      /* ------------------------------------------ */

    case AT_CMP_E:
      SET_CMP(==);
      break;
    case AT_CMP_G:
      SET_CMP(>);
      break;
    case AT_CMP_GE:
      SET_CMP(>=);
      break;
    case AT_CMP_L:
      SET_CMP(<);
      break;
    case AT_CMP_LE:
      SET_CMP(<=);
      break;
    case AT_CMP_NE:
      SET_CMP(!=);
      break;

      /* ------------------------------------------ */
      /* CONDITIONS                                 */
      /* ------------------------------------------ */

    case AT_CND_AND:
      son = tree_node_get_son(tree);
      result.type = SYMBOL_BASIC_BOOL;

      result = region_eval(son);
      CAST(result, SYMBOL_BASIC_BOOL);

      /* Inutile d'évaluer si le premier cas du AND est faux. */
      if(result.value.c)
      {
        result = region_eval(tree_node_get_brother(son));
        CAST(result, SYMBOL_BASIC_BOOL);
      }
      break;

    case AT_CND_OR:
      son = tree_node_get_son(tree);
      result.type = SYMBOL_BASIC_BOOL;

      result = region_eval(son);
      CAST(result, SYMBOL_BASIC_BOOL);

      /* Inutile d'évaluer si le premier cas du OR est vrai. */
      if(!result.value.c)
      {
        result = region_eval(tree_node_get_brother(son));
        CAST(result, SYMBOL_BASIC_BOOL);
      }
      else
        result.value.c = 1;
      break;

    case AT_CND_NOT:
      result = region_eval(son = tree_node_get_son(tree));
      CAST(result, SYMBOL_BASIC_BOOL);
      result.value.c = !result.value.c;
      break;

      /* ------------------------------------------ */
      /* FONCTIONS PREDEFINES                       */
      /* ------------------------------------------ */

    case AT_FUN_READ:
      son = tree_node_get_son(tree);
      do{
          scanf("%s", str_buf);
          res_a.type = SYMBOL_BASIC_STRING;
          res_a.value.s = str_buf;

          size = get_variable_position(son);
          CAST(res_a, data_stack[size].type);

          data_stack[size] = res_a;
      } while((son = tree_node_get_brother(son)) != NULL);

      break;
    case AT_FUN_WRITE:
      fun_write(tree);
      break;
    case AT_FUN_RAND:
      result.type = SYMBOL_BASIC_FLOAT;
      result.value.f = (float)rand() / (float)RAND_MAX;
      break;
    case AT_FUN_STRGET:
      son = tree_node_get_son(tree);
      res_a = region_eval(son);
      res_b = region_eval(tree_node_get_brother(son));
      size = strlen(res_a.value.s);
      result.type = SYMBOL_BASIC_CHAR;
      if(res_b.value.i <= (size * (-1)) || res_b.value.i >= size)
        result.value.c = -1;
      else
        result.value.c = res_a.value.s[res_b.value.i];
      break;
    case AT_FUN_STRSET:
      son = tree_node_get_son(tree);
      res_a = region_eval(son);
      son = tree_node_get_brother(son);
      res_b = region_eval(son);
      size = strlen(res_a.value.s);
      result.type = SYMBOL_BASIC_BOOL;
      if(res_b.value.i <= (size * (-1)) || res_b.value.i >= size)
        result.value.b = false;
      else {
        size = res_b.value.i;
        res_b = region_eval(tree_node_get_brother(son));
        result.value.b = true;
        res_a.value.s[size] = res_b.value.c;
      }
      break;

      /* ------------------------------------------ */
      /* CONTROLES                                  */
      /* ------------------------------------------ */

    case AT_CTL_RETURN:
      result = region_eval(tree_node_get_son(tree)); /* Si pas de valeur à return, alors 0. */
      return_state = true;
      DBG_PRINTF(("Return !\n"));
      break;

    case AT_CTL_IF:
      son = tree_node_get_son(tree);
      res_a = region_eval(son);
      CAST(res_a, SYMBOL_BASIC_BOOL);

      if(res_a.value.c)
      {
        son = tree_node_get_brother(son);
        EVAL_BROTHERS(son);
      }

      /* Si le noeud suivant dans l'arbre n'est pas vide. */
      else if((tree = tree_node_get_brother(tree)) != NULL)
      {
        content = syntax_tree_node_get_content(tree);

        /* Si c'est un noeud else. */
        if(content->type == AT_CTL_ELSE)
        {
          son = tree_node_get_son(tree);
          EVAL_BROTHERS(son);
        }
      }

      break;

    case AT_CTL_WHILE:
      for(;;)
      {
        son = tree_node_get_son(tree);
        res_a = region_eval(son);
        CAST(res_a, SYMBOL_BASIC_BOOL);

        /* Si condition fausse, on quitte. */
        if(!res_a.value.c)
          break;

        son = tree_node_get_brother(son);
        EVAL_BROTHERS(son);
      }
      break;

    case AT_CTL_DO_WHILE:
      for(;;)
      {
        son = tree_node_get_brother(tree_node_get_son(tree));
        EVAL_BROTHERS(son);

        res_a = region_eval(tree_node_get_son(tree));
        CAST(res_a, SYMBOL_BASIC_BOOL);

        /* Si condition fausse, on quitte. */
        if(!res_a.value.c)
          break;
      }
      break;

    case AT_CTL_FOR:
      /* Affectation. */
      son = tree_node_get_son(tree);
      region_eval(son);

      for(;;)
      {
        son = tree_node_get_brother(tree_node_get_son(tree));
        res_a = region_eval(son);
        CAST(res_a, SYMBOL_BASIC_BOOL);

        /* Si condition fausse, on quitte. */
        if(!res_a.value.c)
          break;

        /* Instructions. */
        son = tree_node_get_brother(tree_node_get_brother(son));
        EVAL_BROTHERS(son);

        /* Incrémentation. */
        son = tree_node_get_brother(tree_node_get_brother(tree_node_get_son(tree)));
        region_eval(son);
      }
      break;

    case AT_CTL_SWITCH:
      /* Switch. */
      son = tree_node_get_son(tree);
      res_a = region_eval(son);
      CAST(res_a, SYMBOL_BASIC_INT);

      /* Parcours des "case". */
      for(son = tree_node_get_brother(son); tree_node_get_brother(son) != NULL; son = tree_node_get_brother(son))
      {
        res_b = region_eval(tree_node_get_son(son));
        CAST(res_a, SYMBOL_BASIC_INT);

        /* Si c'est le bon case. */
        if(res_a.value.i == res_b.value.i)
        {
          son = tree_node_get_brother(tree_node_get_son(son));
          EVAL_BROTHERS(son);
          res_a.type = -1;
          break;
        }
      }

      /* default. */
      if(res_a.type != -1)
      {
        son = tree_node_get_son(son);
        EVAL_BROTHERS(son);
      }

      break;

    case AT_CTL_TERNAIRE:
      res_a = region_eval(son = tree_node_get_son(tree));
      CAST(res_a, SYMBOL_BASIC_BOOL);

      /* Si condition vraie. */
      if(res_a.value.c)
        result = region_eval(tree_node_get_brother(son));
      else
        result = region_eval(tree_node_get_brother(tree_node_get_brother(son)));
      break;

    case AT_VAR:
      result = data_stack[get_variable_position(tree)];
      break;

    /* Appel de fonction/procédure. */
    case AT_CTL_CALL:
      result = push_position(tree);
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
    case AT_CTL_ELSE:
    case AT_CTL_ARRAY:
    case AT_CTL_STRUCT:
    case AT_CTL_PROC:
    case AT_CTL_FUN:
    case AT_ARRAY_INDEX:
    case AT_HKEY_INDEX:
    case AT_CTL_BREAK:
    case AT_CTL_CONTINUE:
    case AT_CTL_CASE:
    case AT_CTL_DEFAULT:
      break;

    default:
      break;
  } /* Fin switch. */

  return result;
}

void fun_write(Syntax_tree *tree)
{
  Data res_a;
  Data res_b;
  char *c;
  bool backslash = false, pourcent = false;

  VARIABLE_RESET(res_a);
  VARIABLE_RESET(res_b);

  tree = tree_node_get_son(tree);
  res_a = region_eval(tree);

  for(c= res_a.value.s; *c != '\0'; c++)
    if(*c == '%')
    {
      if(pourcent)
      {
        /* Pas assez de variables. */
        if(tree == NULL)
        {
          fprintf(stderr, "Error : write : there is not enought variables !\n");
          longjmp(jmp, 1);
        }

        tree = tree_node_get_brother(tree);
        res_b = region_eval(tree);
        VARIABLE_PRINT(stdout, res_b);
        pourcent = false;
      }
      else
        pourcent = true;
    }
    else if(*c == '\\')
      backslash = true;
    else if(backslash && *c == 'n')
    {
      printf("\n");
      backslash = false;
    }
    else
      printf("%c", *c);

  return;
}

/* ---------------------------------------------------------------------- */

void exec(Symbol_table *table)
{
  /* Initialisation. */

  int i;
  Region *region;
  Syntax_tree *tree;
  Data result;

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
  srand(time(NULL));
  current_region = -1;
  region = REGION_TABLE_GET(0);

  /* Si dépassement dès le début. */
  if(region->size >= DATA_STACK_SIZE)
    fprintf(stderr, "Error : Stack overflow !\n");
  else if(!setjmp(jmp))
  {
    reset_stack();
    tree = region->tree;
    EVAL_BROTHERS(tree);
    clean_string();
  }
  /* Dépassement de pile. */
  else{}

  /* Libération. */
  for(i = 0; i < n_regions; i++)
    free(sym[i]);

  free(sym);
  free(data_stack);
  (void)result;

  return;
}
