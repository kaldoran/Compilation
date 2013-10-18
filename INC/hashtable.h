/* ---------------------------------------------------------------------- */
/* Filename: hashtable.h                                                  */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-09 - 18:49:57                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _HASHTABLE_
#define _HASHTABLE_

#include "ptypes.h"
                    
/** Taille d'une table de Hachage par defaut. */
#define HASHTABLE_SIZE 4096 

/* Note: 
   - L'id demandé dans plusieurs fonctions est la chaine utilisée 
      pour stocker un élément. (Exemple: La chaine "bonjour")
   - La Hashkey correspond à la clef de hachage utilisée pour stocker un élément.
     (Exemple: La clef 0x123456789)

   Une Hashkey peut facilement être transformée en id et vice-versa.
   Il est préférable de passer par des Hashkey pour une vitesse d'accès moindre. */

/** Structure d'une table de Hachage. */
typedef struct Hashtable Hashtable;

/** Hashcode. */
typedef long unsigned int Hashcode;

/** Clef de Hachage. */
typedef void* Hashkey;

/** Alloue une table de Hachage d'une taille n. */
/* %param size : Taille de la table de Hachage à créer. */
/* %return : NULL en cas d'erreur d'allocation ou la table de Hachage en cas de réussite. */
Hashtable *hashtable_new_with_size(size_t size);

/** Alloue une table de Hachage d'une taille HASHTABLE_SIZE. */
/* %return : NULL en cas d'erreur d'allocation ou la table de Hachage en cas de réussite. */
#define hashtable_new(void) hashtable_new_with_size(HASHTABLE_SIZE)

/** Libère complètement une table de Hachage. */
/* %param h: La Hachtable à libérer. */
/* %param fun : Agit sur la valeur contenue dans chaque case de la table. 
   Pour un usage classique, utiliser "free" en paramètre.
   Note : Le paramètre peut être NULL. */
void hashtable_free(Hashtable *h, void (*fun)(void *value));

/** Redimensionne une table de Hachage. */
/* %param h : La Hachtable à redimensionner. */
/* %param size : La taille de la nouvelle table. */
/* %return : La table de hachage donné en paramètre redimenssionée ou NULL en cas d'échec. */ 
Hashtable *hashtable_resize(Hashtable *h, size_t size);

/** Récupère le nombre d'éléments dans une table de Hachage. */
/* %param h : La Hashtable contenant le nombre d'éléments à récupérer. */
/* %return : Le nombre d'éléments de la table de Hachage. */
unsigned int hashtable_get_size(Hashtable *h);

/** Récupère la chaine relative à une clef de Hachage. */
/* %param h : La Hashtable contenant l'id recherché. */
/* %param hkey : Clef de Hachage de l'id recherché. */ 
/* %return : NULL si la clef est invalide ou la chaine relative en cas de réussite. */
const char *hashtable_get_id(Hashtable *h, Hashkey hkey);

/** Récupère la clef de Hachage relative à un id. */
/* %param h : La Hashtable contenant la clef de Hachage recherchée. */
/* %param id : Id de la clef de Hachage recherchée. */
/* %return : Une clef ou NULL si élément introuvable. */
Hashkey hashtable_get_key(Hashtable *h, const char *id);

/** Récupère la valeur associée à un id. */
/* %param h : La Hashtable contenant la valeur recherchée. */
/* %param id : L'id de la valeur recherchée. */
/* %return : La valeur correspondant à la recherche ou NULL si l'élément n'existe pas. */
void *hashtable_get_value_by_id(Hashtable *h, const char *id);

/** Récupère la valeur associée à une clef de Hachage. */
/* Fonction plus que rapide que hashtable_get_value_by_id. */
/* %param h : La Hashtable contenant la valeur recherchée. */
/* %param hkey : La Hashkey de la valeur recherchée. */
/* %return : La valeur correspondant à la recherche ou NULL si l'élément n'existe pas. */
void *hashtable_get_value_by_key(Hashtable *h, Hashkey hkey);

/** Modifie la valeur d'un élément de la table de Hachage. */
/* %param h : La Hashtable où l'élément doit être modifié. */
/* %param id : Id de l'élément. */
/* %param value : Nouvelle valeur de l'élément. */
/* %return : true si modifié, false si élément non existant. */
bool hashtable_set_value_by_id(Hashtable *h, const char *id, void *value);

/** Modifie la valeur d'un élément de la table de Hachage. */
/* %param h : La Hashtable où l'élément doit être modifié. */
/* %param hkey : Clef de Hachage de l'élément. */
/* %param value : Nouvelle valeur de l'élément. */
/* %return : true si modifié, false si élément non existant. */
bool hashtable_set_value_by_key(Hashtable *h, Hashkey hkey, void *value);

/** Teste l'existence d'une chaine (id) dans une table. */
/* %param h : Hashtable où doit être effectué le test. */
/* %param id : La chaine (id). */
/* %return : Une Hashkey ou NULL. */
Hashkey hashtable_exists_id(Hashtable *h, const char *id);

/** Ajoute une chaine dans une table de Hachage. */
/* %param h : La Hashtable où l'élément doit être ajouté. */
/* %param key : Clef de Hachage de l'élément. */
/* %param value : Valeur de l'élément. */
/* %return : Retourne une clef. */
Hashkey hashtable_add_value(Hashtable *h, const char *key, void *value);

/** Affiche le contenu d'une table de Hachage. */
/* %param h : Hashtable à afficher. */
/* %param fun : Fonction servant à afficher l'élément stocké.
   Le paramètre peut être NULL, dans ce cas, seules les clefs sont affichées. */
void hashtable_print(Hashtable *h, void (*fun)(void *value));

/** Calcule le Hashcode d'une chaine. */
/* %param str : Chaine à calculer. */
/* %return : Hashcode d'une chaine. */
Hashcode hashcode(const char *str);

#endif /* _HASHTABLE_ INCLUDED */
