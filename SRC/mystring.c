/* ---------------------------------------------------------------------- */
/* Filename: mystring.c                                                   */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-22 - 20:14:16                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdlib.h>
#include <string.h>

char *mystrdup(const char *str)
{
  size_t n = strlen(str) + 1;
  char *dup = malloc(n * sizeof *dup);

  if(dup != NULL)
    strcpy(dup, str);

  return dup;
}
