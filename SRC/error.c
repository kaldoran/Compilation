/* ---------------------------------------------------------------------- */
/* Filename: error.c                                                      */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-09-17 - 11:20:27                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include "error.h"

void fatal_error(const char *msg)
{
  fprintf(stderr, "%s\n", msg);
  fprintf(stderr, "Errno: %d - %s\n", errno, strerror(errno));
  exit(EXIT_FAILURE);
}

void dbg_printf(const char *format, ...)
{
  va_list ap;

  va_start(ap, format);
  vfprintf(stderr, format, ap);
  va_end(ap);

  return;
}
