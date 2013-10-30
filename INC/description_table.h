/* ---------------------------------------------------------------------- */
/* Filename: description_table.h                                          */
/* Author: BIGARD Florian                                                 */
/* Date: 2013-10-23 - 13:25:09                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _DESCRIPTION_TABLE_
#define _DESCRIPTION_TABLE_

#include "symbol_table.h"

/** Structure d'une variable. */
typedef struct Variable
{
  Hashkey hkey; /* Numéro lexicographique de la variable. */
  Index_t type; /* Type de la variable. */
} Variable;

/** Structure d'un paramètre. */
typedef Variable Parameter;

/** Structure d'un champ d'une variable. */
typedef Variable Field;

/** Structure d'une dimension. (Pour un tableau) */
typedef struct Dimension
{
  unsigned int bound_lower; /* Borne inférieure de la dimension. */
  unsigned int bound_upper; /* Borne supérieure de la dimension. */
} Dimension;

/** Structure d'une structure. */
typedef struct Structure
{
  unsigned int field_number; /* Nombre de champs de la structure. */
  Field *field;              /* Tableau des champs de la structure. */
} Structure;

/** Structure d'un tableau. */
typedef struct Array
{
  unsigned int dimension_number; /* Nombre de dimensions du tableau. */
  Index_t type;                  /* Type des éléments. */
  Dimension *dimension;          /* Tableau dimensions. */
} Array;

/** Structure d'une fonction. */
typedef struct Function
{
  Index_t return_type;       /* Type de la valeur de retour. */
  unsigned int param_number; /* Nombre de paramètres. */
  Parameter *params;         /* Tableau de paramètres. */
} Function;

/** Structure d'une procedure. */
typedef struct Procedure
{
  unsigned int param_number; /* Nombre de paramètres. */
  Parameter *params;         /* Tableau de paramètres. */
} Procedure;

/** Alloue une structure avec un certain nombre de champs. */
/* %param field_number : Nombre des champs à créer dans la structure. */
/* %return : La structure allouée ou NULL en cas d'échec. */
Structure *structure_new(unsigned int field_number);

/** Libère une structure. */
/* %param *s : Pointeur sur la structure à libérer. */
void structure_free(Structure *s);

/** Alloue un tableau avec un nombre de dimensions et un type spécifiés. */
/* %param dimension_number : Nombre de dimension du tableau à créer. */
/* %param type : Type du tableau à créer. */
/* %return : Le tableau alloué ou NULL en cas d'échec. */
Array *array_new(unsigned int dimension_number, Index_t type);

/* Libère un tableau. */
/* %param *a : Tableau à libérer. */
void array_free(Array *a);

/** Alloue une fonction avec un type à retourner et le nombre de paramètres spécifiés. */
/* %param return_type : Type de retour de la fonction. */
/* %param param_number : Nombre de paramètres que la fonction prend. */
/* %return : La fonction allouée ou NULL en cas d'échec. */
Function *function_new(Index_t return_type, unsigned int param_number);

/** Libère une fonction. */
/* %param *f : Fonction à libérer. */
void function_free(Function *f);

/** Alloue une procédure avec le nombre de paramètres spécifiés. */
/* %param param_number : Nombre de paramètres que la procédure prend. */
/* %return : La procédure allouée ou NULL en cas d'échec. */
Procedure *procedure_new(unsigned int param_number);

/** Libère une procédure. */
/* %param p : Procédure à libérer. */
void procedure_free(Procedure *procedure);

/** Affiche une structure. */
/* %param *structure : Structure à afficher. */
void structure_print(Structure *structure);

/** Affiche une procédure. */
/* %param procedure : Procédure à afficher. */
void procedure_print(Procedure *procedure);

/** Affiche une fonction. */
/* %param function : Fonction à afficher. */
void function_print(Function *function);

/** Affiche un tableau. */
/* %param array : Tableau à afficher. */
void array_print(Array *array);

#endif /* _DESCRIPTION_TABLE_ INCLUDED */
