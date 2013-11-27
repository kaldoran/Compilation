/* ---------------------------------------------------------------------- */
/* Filename: dimensions_buffer.h                                          */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-27 - 19:57:16                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _DIMENSIONS_BUFFER_
#define _DIMENSIONS_BUFFER_

#include "symbol_table.h"

/** Taille maximale du buffer. */
#define MAX_DIMENSIONS_BUFFER_SIZE 256

/** Ajoute un intervalle de dimensions au buffer. */
/* %param bound_lower : Borne inférieure. */
/* %param boud_upper : Borne supérieure. */
/* %return : -1 si buffer plein, 0 sinon. */
int dimensions_buffer_push(unsigned int bound_lower, unsigned int bound_upper);

/** Remet le buffer à 0. */
void dimensions_buffer_reset(void);

/** Copie le buffer dans un tableau de dimensions suffisament grand. */
/* %param dimensions : Destination du buffer. */
/* %return : La destination de la copie. */
Dimension *dimensions_buffer_copy(Dimension *dimensions);

/** Obtenir la taille du buffer. */
/* %return : Taille du buffer. */
unsigned int dimensions_buffer_get_size(void);

#endif /* _DIMENSIONS_BUFFER_ INCLUDED */
