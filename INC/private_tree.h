/* ---------------------------------------------------------------------- */
/* Filename: private_tree.h                                               */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-09-15 - 23:30:38                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _PRIVATE_TREE_
#define _PRIVATE_TREE_

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Structure d'un arbre. */
struct Tree
{
  void *value;           /* Valeur d'un noeud. */
  struct Tree *next;     /* Noeud frère suivant. */
  struct Tree *prev;     /* Noeud frère précédent. */
  struct Tree *children; /* Premier noeud fils. */
  struct Tree *father;   /* Père du noeud. */
  unsigned int depth;    /* Profondeur du noeud. */
};

/* ---------------------------------------------------------------------- */

#endif /* _PRIVATE_TREE_ INCLUDED */
