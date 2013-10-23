/* ---------------------------------------------------------------------- */
/* Filename: list.h                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-09 - 19:05:28                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _LIST_
#define _LIST_

#include "ptypes.h"

/** Structure d'une liste simple. */
typedef struct List List;

/** Alloue une liste. */
/* %return : NULL en cas d'erreur d'allocation ou la liste en cas de réussite. */
List *list_new(void);

/** Libère complètement une liste. */
/* %param l : La liste à libérer. */
/* %param fun : Agit sur la valeur contenue dans chaque noeud. 
   Pour un usage classique, utiliser "free" en paramètre.
   Note : Le paramètre peut être NULL. */
void list_free(List *l, void (*fun)(void *value));

/** Récupère le nombre d'éléments dans une liste. */
/* %param l : La liste contenant le nombre d'éléments à récupérer. */
/* %return : Le nombre d'éléments de la liste. */
unsigned int list_get_size(List *l);

/** Teste si la liste est vide. */
/* %param l : La liste à tester. */
/* %return : true si la liste est vide, false sinon. */
bool list_is_empty(List *l);

/** Ajoute un élément en tête de liste. */
/* %param l : Liste où l'élément doit être ajouté. */
/* %param value : Elément à ajouter. */
/* %return : Adresse de l'élément ou NULL en cas d'échec. */
void *list_add_node(List *l, void *value);

/** Ajoute un élément en fin de liste. */
/* %param l : Liste où l'élément doit être ajouté. */
/* %param value : Elément à ajouter. */
/* %return : Adresse de l'élément ou NULL en cas d'échec. */
void *list_push_node(List *l, void *value);

/** Retourne le premier élément en tête de liste puis raccourci la liste de n - 1. */
/* %param l : Liste contenant l'élément à récupérer. */
/* %return : Le premier élément de la liste ou NULL si liste vide. */
void *list_shift_node(List *l);

/** Retourne le dernier élément en fin de liste puis raccourci la liste de n - 1. */
/* %param l : Liste contenant l'élément à récupérer. */
/* %return : Le dernier élément de la liste ou NULL si liste vide. */
void *list_pop_node(List *l);

/** Applique une fonction à chaque élément d'une liste. */
/* %param l : Liste à parcourir. */
/* %param fun : Fonction à appliquer sur chaque élément. */
void list_map(List *l, void (*fun)(void *value));

#endif /* _LIST_ INCLUDED */
