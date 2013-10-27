/* ---------------------------------------------------------------------- */
/* Filename: variables_buffer.h                                           */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-27 - 16:18:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _VARIABLES_BUFFER_
#define _VARIABLES_BUFFER_

#include "symbol_table.h"

/** Taille maximale du buffer. */
#define MAX_BUFFER_SIZE 1024

/** Ajoute une variable au buffer. */
/* %param hkey : Numéro lexicographique de la variable. */
/* %param type : Type de la variable. */
/* %return : -1 si buffer plein, 0 sinon. */
int variables_buffer_push(Hashkey hkey, Index_t type);

/** Remet le buffer à 0. */
void variables_buffer_reset(void);

/** Copie le buffer dans un tableau de variables suffisament grand. */
/* %param variables : Destination du buffer. */
/* %return : La destination de la copie. */
Variable *variables_buffer_copy(Variable *variables);

#endif /* _VARIABLES_BUFFER_ INCLUDED */
