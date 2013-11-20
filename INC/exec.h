/* ---------------------------------------------------------------------- */
/* Filename: exec.h                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-18 - 20:11:26                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _EXEC_
#define _EXEC_

#include "symbol_table.h"

/** Execute un programme. */
/* %param table : Table des déclarations du programme. */
void exec(Symbol_table *table);

#endif /* _EXEC_ INCLUDED */
