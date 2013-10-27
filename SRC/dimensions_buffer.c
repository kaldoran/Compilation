/* ---------------------------------------------------------------------- */
/* Filename: dimensions_buffer.c                                          */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-27 - 19:57:11                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include "description_table.h"
#include "dimensions_buffer.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Buffer de dimensions. */
static Dimension buffer[MAX_DIMENSIONS_BUFFER_SIZE];

/** Nombre d'éléments. */
static int buffer_size = 0;

/* ---------------------------------------------------------------------- */

int dimensions_buffer_push(unsigned int bound_lower, unsigned int bound_upper)
{
  if(buffer_size == MAX_DIMENSIONS_BUFFER_SIZE)
    return -1; /* Buffer plein. */

  buffer[buffer_size].bound_lower = bound_lower;
  buffer[buffer_size++].bound_upper = bound_upper;
  
  return 0;
}

void dimensions_buffer_reset(void)
{
  buffer_size = 0;
  return;
}

Dimension *dimensions_buffer_copy(Dimension *dimensions)
{
  return memcpy(dimensions, buffer, buffer_size * sizeof *buffer);
}

unsigned int dimensions_buffer_get_size(void)
{
  return buffer_size;
}
