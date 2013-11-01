/* ---------------------------------------------------------------------- */
/* Filename: variables_buffer.c                                           */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-27 - 16:18:25                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <string.h>
#include "description_table.h"
#include "variables_buffer.h"

/* ---------------------------------------------------------------------- */
/* Données internes (privées)                                             */
/* ---------------------------------------------------------------------- */

/** Buffer de variables. */
static Variable buffer[MAX_VARIABLES_BUFFER_SIZE];

/** Nombre d'éléments. */
static int buffer_size = 0;

/** Position actuelle de l'offset. */
static int buffer_offset = 0;

/* ---------------------------------------------------------------------- */

int variables_buffer_push(Hashkey hkey, Index_t type)
{
  if(buffer_size == MAX_VARIABLES_BUFFER_SIZE)
    return -1; /* Buffer plein. */

  buffer[buffer_size].hkey = hkey;
  buffer[buffer_size++].type = type;
  
  return 0;
}

void variables_buffer_set_offset(int offset)
{
  buffer_offset += offset;

  if(offset < 0) offset = 0;
  else if(offset >= MAX_VARIABLES_BUFFER_SIZE)
    offset = MAX_VARIABLES_BUFFER_SIZE - 1;

  return;
}

void variables_buffer_reset(void)
{
  buffer_size = buffer_offset;
  
  return;
}

Variable *variables_buffer_copy(Variable *variables)
{
  return memcpy(variables, buffer + buffer_offset, (buffer_size - buffer_offset) * sizeof *buffer);
}

unsigned int variables_buffer_get_size(void)
{
  return (buffer_size - buffer_offset);
}
