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

/** Charge en mémoire des fichiers résultants d'une compilation. */
/* %param filename : Nom du fichier à charger. */
/* %return : Une table de Hachage contenant les données d'une compilation. */
Hashtable *load(const char *filename);

#endif /* _SAVE_ INCLUDED */
