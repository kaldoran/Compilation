/* ---------------------------------------------------------------------- */
/* Filename: regions_table.h                                              */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-14 - 00:01:19                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _REGIONS_TABLE_
#define _REGIONS_TABLE_

#include "syntax_tree.h"

/* Note : La table des régions n'a pas à être initialisé par une quelconque fonction.
   Sa taille est gérée automatiquement en interne. */

/** Profondeur min de la table des régions. */
/* La taille max étant limitée à la mémoire de la machine utilisée. */
#define REGIONS_TABLE_SIZE_MIN 100

/** Mauvaise région. */
#define BAD_REGION -1

/** Structure d'une région. */
typedef struct Region
{
  size_t size;        /* Taille de la zone de données. */
  unsigned int level; /* Niveau d'imbrication statique. */
  Syntax_tree *tree;  /* Arbre représentatif de la région. */
} Region;

/** Libère la table des régions. */
void regions_table_free(void);

/** Ajoute une région dans la table. */
/* %param size : Taille de la zone de données. */
/* %param level : Niveau d'imbrication statique. */
/* %param tree : Arbre représentatif de la région. */
/* %return : Le niveau de la région actuelle ou la constante BAD_REGION en cas d'erreur. 
   Celle-ci symbolise une erreur d'allocation ou un dépassement de pile. */
int regions_table_add(size_t size, unsigned int level, Syntax_tree *tree);

/** Définit l'arbre d'une région. */
/* %param region : Numéro de la région. */
/* %param tree : Arbre source. */
/* %return : BAD_REGION si la région n'existe pas ou la région sinon. */
int regions_table_set_tree(int region, Syntax_tree *tree);

/** Affiche la table des régions. */
void regions_table_print(void);

#endif /* _REGIONS_TABLE_ INCLUDED */
