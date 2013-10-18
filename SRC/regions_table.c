/* ---------------------------------------------------------------------- */
/* Filename: regions_table.c                                              */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-14 - 00:01:27                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "regions_table.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Niveau de profondeur de la table. */
static int depth = 0;

/** Table des régions. */
static Region **table = NULL;

/* ---------------------------------------------------------------------- */

void regions_table_free(void)
{
  for(depth--; depth >= 0; depth--)
  {
    syntax_tree_free(table[depth]->tree);
    free(table[depth]);
  }

  free(table);
  return;
}

int regions_table_add(size_t size, size_t level, Syntax_tree *tree)
{
  Region *region = malloc(sizeof *region);
  Region **new_table;

  if(region == NULL)
    return BAD_REGION; /* Bad alloc */

  /* Reallocation de la table */
  if(depth % REGIONS_TABLE_SIZE_MIN == 0)
  {
    if((new_table = realloc(table, (depth + REGIONS_TABLE_SIZE_MIN) * sizeof *new_table)) == NULL)
    {
      free(region);
      return BAD_REGION; /* Bad alloc */
    }

    table = new_table;
  }

  /* Ajout de la région. */
  region->size = size;
  region->level = level;
  region->tree = tree;
  table[depth] = region;
  
  return depth++;
}

void regions_table_print(void)
{
  int i;

  printf("Regions table\n");
  printf("Order by: ID, size, level, tree\n");

  for(i = 0; i < depth; i++)
    printf("%04d: (%lu, %u, %p)\n", i, table[i]->size, table[i]->level, (void *)table[i]->tree);

  return;
}
