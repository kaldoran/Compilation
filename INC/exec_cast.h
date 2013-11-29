/* ---------------------------------------------------------------------- */
/* Filename: exec_cast.h                                                  */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-11-20 - 14:20:05                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _EXEC_CAST_
#define _EXEC_CAST_

#include "mystring.h"

#define STR_BUF_SIZE 255

static char str_buf[STR_BUF_SIZE] = "";
static int st_type;
static char *st_str;

/* ---------------------------------------------------------------------- */
/* CASTS                                                                  */
/* ---------------------------------------------------------------------- */

/** Cast de int en un autre type. */
#define CAST_INT(RES, TYPE)                         \
  switch(TYPE)                                      \
  {                                                 \
    case SYMBOL_BASIC_FLOAT:                        \
      RES.value.f = RES.value.i;                    \
      RES.type = SYMBOL_BASIC_FLOAT;                \
      break;                                        \
    case SYMBOL_BASIC_BOOL:                         \
      RES.value.c = RES.value.i != 0;               \
      RES.type = SYMBOL_BASIC_BOOL;                 \
      break;                                        \
    case SYMBOL_BASIC_CHAR:                         \
      RES.value.c = RES.value.i;                    \
      RES.type = SYMBOL_BASIC_CHAR;                 \
      break;                                        \
    case SYMBOL_BASIC_STRING:                       \
      RES.type = SYMBOL_BASIC_STRING_UP;            \
      sprintf(str_buf, "%d", RES.value.i);          \
                                                    \
      if((RES.value.s = mystrdup(str_buf)) == NULL) \
        fatal_error("Bad alloc in cast int");       \
      break;                                        \
  }

/** Cast de float en un autre type. */
#define CAST_FLOAT(RES, TYPE)                              \
  switch(TYPE)                                             \
  {                                                        \
    case SYMBOL_BASIC_INT:                                 \
      RES.value.i = RES.value.f;                           \
      RES.type = SYMBOL_BASIC_INT;                         \
      break;                                               \
    case SYMBOL_BASIC_BOOL:                                \
      RES.value.c = RES.value.f >= 1 || RES.value.f <= -1; \
      RES.type = SYMBOL_BASIC_BOOL;                        \
      break;                                               \
    case SYMBOL_BASIC_CHAR:                                \
      RES.value.c = RES.value.f;                           \
      RES.type = SYMBOL_BASIC_CHAR;                        \
      break;                                               \
    case SYMBOL_BASIC_STRING:                              \
      RES.type = SYMBOL_BASIC_STRING_UP;                   \
      sprintf(str_buf, "%f", RES.value.f);                 \
                                                           \
      if((RES.value.s = mystrdup(str_buf)) == NULL)        \
        fatal_error("Bad alloc in cast float");            \
      break;                                               \
  }

/** Cast de char en un autre type. */
#define CAST_CHAR(RES, TYPE)                        \
  switch(TYPE)                                      \
  {                                                 \
    case SYMBOL_BASIC_INT:                          \
      RES.value.i = RES.value.c;                    \
      RES.type = SYMBOL_BASIC_INT;                  \
      break;                                        \
    case SYMBOL_BASIC_FLOAT:                        \
      RES.value.f = RES.value.c;                    \
      RES.type = SYMBOL_BASIC_FLOAT;                \
      break;                                        \
    case SYMBOL_BASIC_BOOL:                         \
      RES.value.c = RES.value.c != 0;               \
      RES.type = SYMBOL_BASIC_BOOL;                 \
      break;                                        \
    case SYMBOL_BASIC_STRING:                       \
      RES.type = SYMBOL_BASIC_STRING_UP;            \
      sprintf(str_buf, "%c", RES.value.c);          \
                                                    \
      if((RES.value.s = mystrdup(str_buf)) == NULL) \
        fatal_error("Bad alloc in cast char");      \
      break;                                        \
  }

/** Cast de bool en un autre type. */
#define CAST_BOOL(RES, TYPE)                        \
  switch(TYPE)                                      \
  {                                                 \
    case SYMBOL_BASIC_INT:                          \
      RES.value.i = RES.value.c != 0;               \
      RES.type = SYMBOL_BASIC_INT;                  \
      break;                                        \
  case SYMBOL_BASIC_FLOAT:                          \
      RES.value.f = RES.value.c != 0;               \
      RES.type = SYMBOL_BASIC_FLOAT;                \
      break;                                        \
    case SYMBOL_BASIC_CHAR:                         \
      RES.value.c = RES.value.c != 0;               \
      RES.type = SYMBOL_BASIC_CHAR;                 \
      break;                                        \
    case SYMBOL_BASIC_STRING:                       \
      RES.type = SYMBOL_BASIC_STRING_UP;            \
                                                    \
      if(RES.value.c)                               \
        sprintf(str_buf, "true");                   \
      else                                          \
        sprintf(str_buf, "false");                  \
                                                    \
     if((RES.value.s = mystrdup(str_buf)) == NULL ) \
       fatal_error("Bad alloc in cast bool");       \
      break;                                        \
  }

/** Cast de string en un autre type. */
#define CAST_STRING(RES, TYPE)                  \
  do {                                          \
    st_type = RES.type;                         \
    st_str = RES.value.s;                       \
                                                \
    switch(TYPE)                                \
    {                                           \
      case SYMBOL_BASIC_INT:                    \
        RES.value.i = atoi(RES.value.s);        \
        RES.type = SYMBOL_BASIC_INT;            \
        break;                                  \
      case SYMBOL_BASIC_FLOAT:                  \
        RES.value.f = atof(RES.value.s);        \
        RES.type = SYMBOL_BASIC_FLOAT;          \
        break;                                  \
      case SYMBOL_BASIC_BOOL:                   \
        RES.value.c = strlen(RES.value.s) != 0; \
        RES.type = SYMBOL_BASIC_BOOL;           \
        break;                                  \
      case SYMBOL_BASIC_CHAR:                   \
        RES.value.c = RES.value.s[0];           \
        RES.type = SYMBOL_BASIC_CHAR;           \
        break;                                  \
    }                                           \
                                                \
    if(st_type == SYMBOL_BASIC_STRING_UP)       \
      free(st_str);                             \
  } while(0)

/* ---------------------------------------------------------------------- */
/* CAST GENERALISTE                                                       */
/* ---------------------------------------------------------------------- */

/** Cast en un autre type. Détecte le type d'entrée. */
#define CAST(RES, TYPE)          \
  switch(RES.type)               \
  {                              \
    case SYMBOL_BASIC_INT:       \
      CAST_INT(RES, TYPE);       \
      break;                     \
    case SYMBOL_BASIC_FLOAT:     \
      CAST_FLOAT(RES, TYPE);     \
      break;                     \
    case SYMBOL_BASIC_BOOL:      \
      CAST_BOOL(RES, TYPE);      \
      break;                     \
    case SYMBOL_BASIC_CHAR:      \
      CAST_CHAR(RES, TYPE);      \
      break;                     \
    case SYMBOL_BASIC_STRING:    \
    case SYMBOL_BASIC_STRING_UP: \
      CAST_STRING(RES, TYPE);    \
      break;                     \
  }

#endif /* _EXEC_CAST_ INCLUDED */
