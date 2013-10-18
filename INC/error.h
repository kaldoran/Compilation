/* ---------------------------------------------------------------------- */
/* Filename: error.h                                                      */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-17 - 11:19:22                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _ERROR_
#define _ERROR_

/** Affiche un message d'erreur (sur stderr) et le dernier code errno. */
/* Quitte le programme avec pour code de retour EXIT_FAILURE. */
/* %param msg : Message transmis.  */
void fatal_error(const char *msg);

#endif /* _ERROR_ INCLUDED */
