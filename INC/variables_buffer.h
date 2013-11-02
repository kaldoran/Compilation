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
#define MAX_VARIABLES_BUFFER_SIZE 4096

/** Ajoute une variable au buffer. */
/* %param hkey : Numéro lexicographique de la variable. */
/* %param type : Type de la variable. */
/* %return : -1 si buffer plein, 0 sinon. */
int variables_buffer_push(Hashkey hkey, Index_t type);

/** Définit où commence le buffer. */
/* %param offset : Valeur de décalage dans le buffer.
   Une valeur négative recule, à l'inverse, une positive avance. */
void variables_buffer_set_offset(int offset);

/** Reset les valeurs courantes du buffer. (Par le biais de l'offset en cours.) */
void variables_buffer_reset(void);

/** Copie le buffer dans un tableau de variables suffisament grand. */
/* %param variables : Destination du buffer. */
/* %return : La destination de la copie. */
Variable *variables_buffer_copy(Variable *variables);

/** Obtenir la taille du buffer. */
/* %return : Taille du buffer. */
unsigned int variables_buffer_get_size(void);

#endif /* _VARIABLES_BUFFER_ INCLUDED */
