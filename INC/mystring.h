/* ---------------------------------------------------------------------- */
/* Filename: mystring.h                                                   */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-22 - 20:14:09                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _MYSTRING_
#define _MYSTRING_

/** Crée une copie d'une chaine. */
/* strdup existe mais est non conforme ansi. */
/* %param str : Chaîne à copier. */
/* %return : Une copie de la chaîne str ou NULL en cas d'erreur d'allocation. */
char *mystrdup(const char *str);

#endif /* _MYSTRING_ INCLUDED */
