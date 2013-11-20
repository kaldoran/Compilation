/* ---------------------------------------------------------------------- */
/* Filename: regions_table.h                                              */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-14 - 00:01:19                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _REGIONS_TABLE_
#define _REGIONS_TABLE_

#include "syntax_tree.h"
#include "lexeme_table.h"

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

/** Obtenir une région de la table. */
/* %param region : Numéro de la région. */
/* %return : NULL si non trouvé, la région sinon. */
Region *region_table_get(int region);

/** Obtenir le nombre de régions. */
/* %return : Nombre de régions. */
int regions_table_get_size(void);

/** Définit l'arbre d'une région. */
/* %param region : Numéro de la région. */
/* %param tree : Arbre source. */
/* %return : BAD_REGION si la région n'existe pas ou la région sinon. */
int regions_table_set_tree(int region, Syntax_tree *tree);

/** Affiche la table des régions. */
void regions_table_print(void);

/** Sauvegarde la table des régions dans le fichier spécifié. */
/* %param filename : Nom du fichier de sauvegarde. */
void regions_table_save(const char *filename);

/** Charge la table des régions. 
    Necessite l'initialisation des tables principales. */
/* %param filename : Nom du fichier à charger. */
void regions_table_load(Lexeme_table *table, const char *filename);

#endif /* _REGIONS_TABLE_ INCLUDED */
