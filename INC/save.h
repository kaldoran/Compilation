/* ---------------------------------------------------------------------- */
/* Filename: save.h                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-10-30 - 10:52:39                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _SAVE_
#define _SAVE_

#include "symbol_table.h"

/** Sauvegarde l'intégralité des données de la compilation. */
/* %param filename : Nom du fichier où sauvegarder les résultats de la compilation. */
/* %param hashtable : Table contenant les lexèmes, déclarations, et descriptions. */
void save(const char *filename, Hashtable *h);

/** Charge en mémoire des fichiers résultants d'une compilation.
    Crée un tableau index_array. */
/* %param filename : Nom du fichier à charger. */
/* %return : Une table de Hachage contenant les données d'une compilation. */
Hashtable *load(const char *filename);

/** Crée un tableau contenant toutes les adresses mémoires des déclarations. 
    Utile pour obtenir un indice correspondant à une adresse.
    Utilisé par les fonctions de sauvegarde du compilateur. */
void index_array_new(Hashtable *h);

/** Libérer le tableau d'index. */
void index_array_free(void);

/** Retourne le tableau d'index s'il est effectivement crée. */
/* %return : Le tableau d'index. */
Index_t index_array_get(void);

/** Retourne le nombre de déclarations dans le tableau d'index. */
/* %return : Nombre d'éléments dans le tableau. */
unsigned int index_array_get_size(void);

/** Obtenir l'id d'un index de la table de déclarations. */
/* %param index : Index sur un champ de déclaration. */
/* %return : L'id ou -1 si il n'existe pas. */
int index_array_get_id(Index_t index);

#endif /* _SAVE_ INCLUDED */
