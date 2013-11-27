/* ---------------------------------------------------------------------- */
/* Filename: regions_table.c                                              */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-14 - 00:01:27                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "regions_table.h"
#include "error.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Niveau de profondeur de la table. */
static int depth = 0;

/** Table des régions. */
static Region **r_table = NULL;

/* ---------------------------------------------------------------------- */

void regions_table_free(void)
{
  for(depth--; depth >= 0; depth--)
  {
    syntax_tree_free(r_table[depth]->tree);
    free(r_table[depth]);
  }

  free(r_table);
  return;
}

int regions_table_add(size_t size, unsigned int level, Syntax_tree *tree)
{
  Region *region = malloc(sizeof *region);
  Region **new_r_table;

  if(region == NULL)
    return BAD_REGION; /* Région non allouée ! */

  /* Reallocation de la r_table */
  if(depth % REGIONS_TABLE_SIZE_MIN == 0)
  {
    if((new_r_table = realloc(r_table, (depth + REGIONS_TABLE_SIZE_MIN) * sizeof *new_r_table)) == NULL)
    {
      free(region);
      return BAD_REGION; /* Bad alloc. */
    }

    r_table = new_r_table;
  }

  /* Ajout de la région. */
  region->size = size;
  region->level = level;
  region->tree = tree;
  r_table[depth] = region;

  return depth++;
}

Region *region_table_get(int region)
{
  if(region >= depth || region < 0)
    return NULL;
  return r_table[region];
}

int regions_table_get_size(void)
{
  return depth;
}

int regions_table_set_tree(int region, Syntax_tree *tree)
{
  if(region < 0 || region >= depth)
    return BAD_REGION; /* Région inexistante. */

  r_table[region]->tree = tree;

  return region;
}

void regions_table_print(void)
{
  int i;

  printf("Regions table\n");
  printf("Order by: ID, size, level, tree\n\n");

  for(i = 0; i < depth; i++)
  {
    printf("%04d: (%lu, %u, %p)\n", i, (long unsigned int)r_table[i]->size, r_table[i]->level,
           (void *)r_table[i]->tree);
    syntax_tree_print(r_table[i]->tree);
    printf("\n");
  }

  return;
}

void regions_table_save(const char *filename)
{
  FILE *file;
  int i;

  if((file = fopen(filename, "w")) == NULL)
    fatal_error("regions_table_save");

  fprintf(file, "%d\n", depth);

  for(i = 0; i < depth; i++)
  {
    fprintf(file, "%lu %u\n", (long unsigned int)r_table[i]->size, r_table[i]->level);
    syntax_tree_save(file, r_table[i]->tree);
  }

  fclose(file);

  return;
}

void regions_table_load(Lexeme_table *table, const char *filename)
{
  FILE *file;
  int i, t_depth;

  if((file = fopen(filename, "r")) == NULL)
    fatal_error("regions_table_load");

  fscanf(file, "%d\n", &t_depth);

  for(i = 0; i < t_depth; i++)
  {
    if(regions_table_add(0, 0, NULL) == BAD_REGION)
      fatal_error("regions_table_load");

    fscanf(file, "%lu %u\n", (long unsigned int *)&r_table[i]->size, &r_table[i]->level);
    r_table[i]->tree = syntax_tree_load(table, file);
  }

  depth = t_depth;
  fclose(file);

  return;
}
