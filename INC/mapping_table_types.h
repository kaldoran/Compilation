/* ---------------------------------------------------------------------- */
/* Filename: mapping_table_types.h                                        */
/* Author: BIGARD Florian                                                 */
/* Date: 2013-10-23 - 13:25:09                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _MAPPING_TABLE_TYPES_
#define _MAPPING_TABLE_TYPES_

/* !!!!!!!!! Normalement c'est pas bon, c'est la table des symboles qui fait un include sur mapping_table_types, seulement j'en ai besoin pour le Index_t. Il faudra donc le déplacer !!!!!!!!!!!!!!!!!!!!!*/
#include "symbol_table.h" 

/** Structure d'une variable. */
typedef struct Variable
{
    Hashkey hkey; /* Numéro lexicographique de la variable. */
    Index_t type; /* Type de la variable. */
} Variable;

/** Structure d'un paramètre qui n'est autre qu'une variable. */
typedef Variable Parameter;

/** Structure d'un champ d'une structure qui n'est autre qu'une variable. */
typedef Variable Field;

/** Structure d'une dimension (pour un tableau). */
typedef struct Dimension
{
    unsigned int bound_lower; /* Borne inférieure de la dimension. */
    unsigned int bound_upper; /* Borne supérieure de la dimension. */
} Dimension;

/** Structure d'une structure. */
typedef struct Structure
{
    unsigned int field_number; /* Nombre de champs de la structure. */ 
    Hashkey hkey; /* Nom lexicographique. */
    Field *field; /* Tableau de structure des champs (donc des variables) de la structure. */
    /* ????? deplacement exécution ????? */
} Structure;

/** Structure d'un tableau. */
typedef struct Array
{
    unsigned int dimension_number; /* Nombre de dimensions du tableau. */
    Index_t type; /* Type des éléments. */
    Dimension *dimension; /* Tableau de structures de dimensions. */
} Array;

/** Structure d'une fonction. */
typedef struct Function
{
    Index_t return_type; /* Type de la valeur de retour. */
    unsigned int param_number; /* Nombre de paramètres. */
    Parameter *params; /* Tableau de structures de paramètres (qui sont donc des variables). */
} Function;

/** Structure d'une procedure. */
typedef struct Procedure
{
    unsigned int param_number; /* Nombre de paramètres. */
    Parameter *params; /* Tableau de structures de paramètres. */
} Procedure;

/** Alloue une structure avec un nombre de champs et un hkey spécifiés. */
/* %param field_number : Nombre des champs à créer dans la structure. */ 
/* %param hkey : Clé de hashage de la structure. */
/* %return : La structure allouée ou NULL en cas d'échec. */
Structure *structure_new(unsigned int field_number, Hashkey hkey);

/** Alloue un tableau avec un nombre de dimensions et un type spécifiés. */
/* %param dimension_number : Nombre de dimension du tableau à créer. */
/* %param type : Type du tableau à créer. */
/* %return : Le tableau alloué ou NULL en cas d'échec. */
Array *array_new(unsigned int dimension_number, Index_t type);

/** Alloue une fonction avec un type à retourner et le nombre de paramètres spécifiés. */
/* %param return_type : Type de retour de la fonction. */
/* %param param_number : Nombre de paramètres que la fonction prend. */
/* %return : La fonction allouée ou NULL en cas d'échec. */
Function *function_new(Index_t return_type, unsigned int param_number);

/** Alloue une procédure avec le nombre de paramètres spécifiés. */
/* %param param_number : Nombre de paramètres que la procédure prend. */
/* %return : La procédure allouée ou NULL en cas d'échec. */
Procedure *procedure_new(unsigned int param_number);

#endif /* _MAPPING_TABLE_TYPES__ INCLUDED */

