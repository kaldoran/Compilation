/* ---------------------------------------------------------------------- */
/* Filename: exec_cast.h                                                  */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-11-20 - 14:20:05                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _EXEC_CAST_
#define _EXEC_CAST_

/* ---------------------------------------------------------------------- */
/* CASTS                                                                  */
/* ---------------------------------------------------------------------- */

/** Cast de int en un autre type. */
#define CAST_INT(RES, TYPE)          \
  switch(TYPE)                       \
  {                                  \
    case SYMBOL_BASIC_FLOAT:         \
      RES.value.f = RES.value.i;     \
      RES.type = SYMBOL_BASIC_FLOAT; \
      break;                         \
    case SYMBOL_BASIC_BOOL:          \
      RES.value.c = !!RES.value.i;   \
      RES.type = SYMBOL_BASIC_BOOL;  \
      break;                         \
    case SYMBOL_BASIC_CHAR:          \
      RES.value.c = RES.value.i;     \
      RES.type = SYMBOL_BASIC_CHAR;  \
      break;                         \
    case SYMBOL_BASIC_STRING:        \
      break;                         \
  } 

/** Cast de float en un autre type. */
#define CAST_FLOAT(RES, TYPE)       \
  switch(TYPE)                      \
  {                                 \
    case SYMBOL_BASIC_INT:          \
      RES.value.i = RES.value.f;    \
      RES.type = SYMBOL_BASIC_INT;  \
      break;                        \
    case SYMBOL_BASIC_BOOL:         \
      RES.value.c = !!RES.value.f;  \
      RES.type = SYMBOL_BASIC_BOOL; \
      break;                        \
    case SYMBOL_BASIC_CHAR:         \
      RES.value.c = RES.value.f;    \
      RES.type = SYMBOL_BASIC_CHAR; \
      break;                        \
    case SYMBOL_BASIC_STRING:       \
      break;                        \
  }

/** Cast de char en un autre type. */
#define CAST_CHAR(RES, TYPE)         \
  switch(TYPE)                       \
  {                                  \
    case SYMBOL_BASIC_INT:           \
      RES.value.i = RES.value.c;     \
      RES.type = SYMBOL_BASIC_INT;   \
      break;                         \
    case SYMBOL_BASIC_FLOAT:         \
      RES.value.f = RES.value.c;     \
      RES.type = SYMBOL_BASIC_FLOAT; \
      break;                         \
    case SYMBOL_BASIC_BOOL:          \
      RES.value.c = !!RES.value.c;   \
      RES.type = SYMBOL_BASIC_BOOL;  \
      break;                         \
    case SYMBOL_BASIC_STRING:        \
      break;                         \
  }

/** Cast de bool en un autre type. */
#define CAST_BOOL(RES, TYPE)         \
  switch(TYPE)                       \
  {                                  \
    case SYMBOL_BASIC_INT:           \
      RES.value.i = !!RES.value.c;   \
      RES.type = SYMBOL_BASIC_INT;   \
      break;                         \
    case SYMBOL_BASIC_FLOAT:         \
      RES.value.f = !!RES.value.c;   \
      RES.type = SYMBOL_BASIC_FLOAT; \
      break;                         \
    case SYMBOL_BASIC_CHAR:          \
      RES.value.c = !!RES.value.c;   \
      RES.type = SYMBOL_BASIC_CHAR;  \
      break;                         \
    case SYMBOL_BASIC_STRING:        \
      break;                         \
  }

/** Cast de string en un autre type. */
#define CAST_STRING(RES, TYPE)                \
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
      RES.value.c = !!RES.value.c;            \
      RES.type = SYMBOL_BASIC_CHAR;           \
      break;                                  \
  }

/* ---------------------------------------------------------------------- */
/* CAST GENERALISTE                                                       */
/* ---------------------------------------------------------------------- */

/** Cast en un autre type. Détecte le type d'entrée. */
#define CAST(RES, TYPE)       \
  switch(RES.type)            \
  {                           \
    case SYMBOL_BASIC_INT:    \
      CAST_INT(RES, TYPE);    \
      break;                  \
    case SYMBOL_BASIC_FLOAT:  \
      CAST_FLOAT(RES, TYPE);  \
      break;                  \
    case SYMBOL_BASIC_BOOL:   \
      CAST_BOOL(RES, TYPE);   \
      break;                  \
    case SYMBOL_BASIC_CHAR:   \
      CAST_CHAR(RES, TYPE);   \
      break;                  \
    case SYMBOL_BASIC_STRING: \
      CAST_STRING(RES, TYPE); \
      break;                  \
  }

#endif /* _EXEC_CAST_ INCLUDED */
