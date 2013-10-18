/* ---------------------------------------------------------------------- */
/* Filename: private_tree.h                                               */
/* Author: ABHAMON Ronan                                                  */
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
  void *value;          /* Valeur d'un noeud. */
  unsigned char size_s; /* Nombre de fils du noeud. */
  struct Tree *father;  /* Père du noeud. */
  struct Tree **sons;   /* Tableau de fils. */
  unsigned char depth;  /* Profondeur du noeud. */
};

/* ---------------------------------------------------------------------- */

#endif /* _PRIVATE_TREE_ INCLUDED */
