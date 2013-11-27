/* ---------------------------------------------------------------------- */
/* Filename: save.c                                                       */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-30 - 10:52:35                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "private_list.h"
#include "lexeme_table.h"
#include "private_hashtable.h"
#include "description_table.h"
#include "error.h"
#include "save.h"

/** Longueur max d'un lexeme. */
#define LEXEME_SIZE 255

/** Taille max d'une ligne lu dans un fichier de compilation. */
#define BUFFER_SIZE 1024

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Tableau contenant les adresses mémoires des déclarations. */
static Index_t *index_array = NULL;

/** Nombre de déclarations dans le tableau. */
static unsigned int n_symbols = 0;

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/** Compter le nombre de symboles dans la table de Hachage. */
/* Fonction appellée par hashtable_foreach_value. */
/* %param value : Une Déclaration. */
/* %param cvalue : Compteur de déclarations. */
void count_symbol(void *value, void *cvalue);

/** Remplir le tableau des adresses mémoires des déclarations. */
/* Fonction appellée par hashtable_foreach_value. */
/* %param value : Une Déclaration. */
/* %param cvalue : Compteur de déclarations. */
void fill_index_array(void *value, void *cvalue);

/* ---------------------------------------------------------------------- */

void count_symbol(void *value, void *cvalue)
{
  Symbol *s = value;

  for(; s != NULL; s = s->next)
    (*(unsigned int *)cvalue)++;

  return;
}

void fill_index_array(void *value, void *cvalue)
{
  Symbol *s = value;

  for(; s != NULL; s = s->next)
    index_array[(*(int *)cvalue)++] = s;

  return;
}

/* ---------------------------------------------------------------------- */

void save(const char *filename, Hashtable *h)
{
  FILE *file;
  unsigned int i = 0, j;
  List_node *ln;
  Symbol *s;

  Array *array;
  Structure *structure;
  Function *function;
  Procedure *procedure;

  if((file = fopen(filename, "w")) == NULL)
    fatal_error("save");

  /* Print : Taille de la table de Hachage. */
  /* Print : Nombre de lexèmes. */
  fprintf(file, "%u\n", hashtable_get_size_max(h));
  fprintf(file, "%u\n", hashtable_get_size(h));

  /* Print : Nombre de déclarations. */
  fprintf(file, "%u\n", n_symbols);

  /* Parcours des lexèmes. */
  for(ln = h->hvalues->start; ln != NULL; ln = ln->next)
  {
    /* Print : Lexème et première déclaration suivante. */
    fprintf(file, "L %s ", HNVALUE(ln)->id);
    HNVALUE(ln)->value != NULL ? fprintf(file, "%u\n", i) : fprintf(file, "-1\n");

    /* Parcours des déclarations. */
    for(s = HNVALUE(ln)->value; s != NULL; i++, s = s->next)
    {
      /* Print : Déclaration de variable (TYPE, REGION, ID, EXEC). */
      if(s->type == SYMBOL_TYPE_VAR)
        fprintf(file, "S %d %d %d %lu\n", s->type, s->region, index_array_get_id(s->index),
                (unsigned long int)s->exec);
      else
      {
        fprintf(file, "S %d %d -1 %lu\n", s->type, s->region, (unsigned long int)s->exec);

        switch(s->type)
        {
          case SYMBOL_TYPE_STRUCT:
            structure = s->index;
            fprintf(file, "%u\n", structure->field_number);

            for(j = 0; j < structure->field_number; j++)
              fprintf(file, "%d %lu %s\n", index_array_get_id(structure->field[j].type),
		      (unsigned long int)structure->exec[j],
		      lexeme_table_get(h, structure->field[j].hkey));
            break;

          case SYMBOL_TYPE_ARRAY:
            array = s->index;
            fprintf(file, "%u %d\n", array->dimension_number, index_array_get_id(array->type));

            for(j = 0; j < array->dimension_number; j++)
              fprintf(file, "%u %u\n", array->dimension[j].bound_lower, array->dimension[j].bound_upper);
            break;

          case SYMBOL_TYPE_FUNCTION:
            function = s->index;
            fprintf(file, "%u %d\n", function->param_number, index_array_get_id(function->return_type));

            for(j = 0; j < function->param_number; j++)
              fprintf(file, "%d %s\n", index_array_get_id(function->params[j].type),
                      lexeme_table_get(h, function->params[j].hkey));
            break;

          case SYMBOL_TYPE_PROCEDURE:
            procedure = s->index;
            fprintf(file, "%u\n", procedure->param_number);

            for(j = 0; j < procedure->param_number; j++)
              fprintf(file, "%d %s\n", index_array_get_id(procedure->params[j].type),
                      lexeme_table_get(h, procedure->params[j].hkey));
            break;
        }
      }
    }
  }

  fclose(file);

  return;
}

Hashtable *load(const char *filename)
{
  Hashtable *h;
  FILE *file;
  unsigned int i = 0, j, k;
  Symbol *s, *origin = NULL;
  List_node *ln;

  /* Lexeme. */
  Hashkey hkey = NULL;

  /* Buffer(Lexeme). */
  char buffer[BUFFER_SIZE];
  char lexeme[LEXEME_SIZE];

  /* Données. */
  Array *array;
  Structure *structure;
  Function *function;
  Procedure *procedure;

  /* ------------- CHARGEMENT BASE ------------- */

  if((file = fopen(filename, "r")) == NULL)
    fatal_error("load");

  /* Taille max de la table de Hachage. */
  fscanf(file, "%u", &i);
  printf("Hashtable size_max : %u\n", i);

  if((h = hashtable_new_with_size(i)) == NULL)
    fatal_error("load");

  /* Nombre de lexèmes. */
  fscanf(file, "%u", &i);
  printf("Lexemes : %u\n", i);

  /* Nombre de déclarations. */
  fscanf(file, "%u\n", &n_symbols);
  printf("Symbols : %u\n", n_symbols);

  /* Création de l'index_array. */
  hashtable_foreach_value(h, count_symbol, &n_symbols);

  if(n_symbols > 0 && (index_array = malloc(n_symbols * sizeof *index_array)) == NULL)
    fatal_error("load");

  /* ---------------- PARCOURS ----------------- */

  /* Remplissage de la table (base). Parcours des lexèmes. */
  while(fgets(buffer, BUFFER_SIZE, file) != NULL)
  {
    /* Lexème. */
    if(*buffer == 'L')
    {
      sscanf(buffer, "L %s %d", lexeme, (int *)&i);

      if((hkey = lexeme_table_add(h, lexeme)) == NULL)
        fatal_error("load");
    }

    /* Déclaration. */
    else if(*buffer == 'S')
    {
      if((s = calloc(1, sizeof *s)) == NULL)
        fatal_error("load");

      sscanf(buffer, "S %d %d %*d %lu\n", (int *)&s->type, &s->region, (unsigned long int *)&s->exec);
      index_array[i++] = s;

      /* Si aucune déclaration. */
      if(((Hashvalue *)hkey)->value == NULL)
      {
         ((Hashvalue *)hkey)->value = s;
         origin = s;
      }
      /* Si déjà une déclaration. */
      else
      {
        origin->next = s;
        origin = s;
      }
    }
  }
  /* ---------------- PARCOURS 2 ---------------- */

  fseek(file, 0, SEEK_SET);

  for(ln = h->hvalues->start; ln != NULL; ln = ln->next)
    /* Parcours des déclarations. */
    for(s = HNVALUE(ln)->value; s != NULL; s = s->next)
      for(;;)
      {
        fgets(buffer, BUFFER_SIZE, file);

        /* Symbole trouvé. */
        if(*buffer == 'S')
        {
          switch(s->type)
          {
            case SYMBOL_TYPE_VAR:
              sscanf(buffer, "S %*d %*d %u %*d", &j);
              s->index = index_array[j];
              break;

            case SYMBOL_TYPE_STRUCT:
              fscanf(file, "%u", &i);

              if((s->index = structure = structure_new(i)) == NULL)
                fatal_error("load");

              for(k = 0; k < i; k++)
              {
                fscanf(file, "%u %lu %s", &j, &structure->exec[k], lexeme);
                structure->field[k].type = index_array[j];
                structure->field[k].hkey = hashtable_get_key(h, lexeme);
              }
              break;

            case SYMBOL_TYPE_ARRAY:
              fscanf(file, "%u %u", &i, &j);

              if((s->index = array = array_new(i, index_array[j])) == NULL)
                fatal_error("load");

              for(k = 0; k < i; k++)
                fscanf(file, "%u %u", &array->dimension[k].bound_lower, &array->dimension[k].bound_upper);
              break;

            case SYMBOL_TYPE_FUNCTION:
              fscanf(file, "%u %u", &i, &j);

              if((s->index = function = function_new(index_array[j], i)) == NULL)
                fatal_error("load");

              for(k = 0; k < i; k++)
              {
                fscanf(file, "%u %s", &j, lexeme);
                function->params[k].type = index_array[j];
                function->params[k].hkey = hashtable_get_key(h, lexeme);
              }

              break;

            case SYMBOL_TYPE_PROCEDURE:
              fscanf(file, "%u", &i);

              if((s->index = procedure = procedure_new(i)) == NULL)
                fatal_error("load");

              for(k = 0; k < i; k++)
              {
                fscanf(file, "%u %s", &j, lexeme);
                procedure->params[k].type = index_array[j];
                procedure->params[k].hkey = hashtable_get_key(h, lexeme);
              }

              break;
          }

          break;
        }
      }

  fclose(file);

  return h;
}

void index_array_new(Hashtable *h)
{
  int i = 0;

  /* Création de l'index_array. */
  hashtable_foreach_value(h, count_symbol, &n_symbols);

  if(n_symbols > 0 && (index_array = malloc(n_symbols * sizeof *index_array)) == NULL)
    fatal_error("index_array_new");

  /* Remplissage de l'index_array. */
  hashtable_foreach_value(h, fill_index_array, &i);

  return;
}

void index_array_free(void)
{
  free(index_array);
  index_array = NULL;
  n_symbols = 0;
}

Index_t index_array_get(void)
{
  return index_array;
}

unsigned int index_array_get_size(void)
{
  return n_symbols;
}

int index_array_get_id(Index_t index)
{
  int i;

  for(i = 0; i < n_symbols; i++)
    if(index_array[i] == index)
      return i;

  return -1;
}
