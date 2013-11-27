/* ---------------------------------------------------------------------- */
/* Filename: private_hashtable.h                                          */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-30 - 13:10:27                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _PRIVATE_HASHTABLE_
#define _PRIVATE_HASHTABLE_

/** Cast d'un noeud de la table de Hachage en Hashvalue. */
#define HNVALUE(NODE) ((Hashvalue *)NODE->value)

/** Calcule l'index d'un Hashcode. */
#define HCODE(HASH, ID) (hashcode(ID) % HASH->size_max)

/* ---------------------------------------------------------------------- */
/* Structures internes (privées)                                          */
/* ---------------------------------------------------------------------- */

/** Structure d'une table de Hachage. */
struct Hashtable
{
  unsigned int size;     /* Nombre d'éléments dans la table. */
  unsigned int size_max; /* Nombre d'éléments max dans la table. */
  List **array;          /* Tableau de pointeurs sur les listes d'éléments. */
  List *hvalues;         /* Pointeur sur valeurs/clefs. Permet d'éviter de parcourir
                            toute la table pour appliquer une fonction sur toutes
                            les valeurs. */
};

/** Valeur d'un élément d'une table de Hachage. */
typedef struct Hashvalue
{
  char *id;    /* Référence de la valeur. (Key) */
  size_t len;  /* Longueur de la référence. */
  void *value; /* Valeur. */
} Hashvalue;

#endif /* _PRIVATE_HASHTABLE_ INCLUDED */
