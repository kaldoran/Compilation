/* ---------------------------------------------------------------------- */
/* Filename: private_list.h                                               */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-09-15 - 03:19:27                                            */
/*                                                                        */
/* Voir list.c et hashtable.c pour utilisation.                           */
/* ---------------------------------------------------------------------- */

#ifndef _PRIVATE_LIST_
#define _PRIVATE_LIST_

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Structure d'un noeud d'une liste simple. */
typedef struct List_node
{
  void *value;            /* Valeur d'un noeud. */
  struct List_node *next; /* Noeud suivant. */
} List_node;

/** Structure d'une liste simple. */
struct List
{
  unsigned int size;      /* Taille d'une liste. */
  List_node *start;       /* Premier noeud d'une liste. */
  struct List_node *end;  /* Dernier noeud de la liste. */
};

/* ---------------------------------------------------------------------- */

#endif /* _PRIVATE_LIST_ INCLUDED */
