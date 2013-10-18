/* ---------------------------------------------------------------------- */
/* Filename: ptypes.h                                                     */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-15 - 00:26:59                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _PTYPES_
#define _PTYPES_

/** Affichage de la taille d'un type quelconque. */
#define PRINT_SIZE(NAME, TYPE) printf("Size of %s: %lu\n", NAME, sizeof(TYPE))

/** Type bool. */
typedef enum bool 
{
  true = 1,
  false = 0
} bool;

#endif /* _PTYPES_ INCLUDED */
