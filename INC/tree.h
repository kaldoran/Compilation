/* ---------------------------------------------------------------------- */
/* Filename: tree.h                                                       */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-15 - 23:06:52                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _TREE_
#define _TREE_

#include "ptypes.h"

/** Structure d'un arbre. */
typedef struct Tree Tree;

/** Alloue un noeud d'un arbre. */
/* %param value : Valeur du noeud crée. */
/* %return : NULL en cas d'erreur d'allocation ou un arbre en cas de réussite. */
Tree *tree_node_new(void *value);

/** Libère complètement un arbre. */
/* %param t : L'arbre à libérer.
   Si t n'est pas la racine, la totalité de l'arbre est quand même supprimé
   en remontant jusqu'à cette dite racine. */
/* %param fun : Agit sur la valeur contenue dans chaque noeud de l'arbre. 
   Pour un usage classique, utiliser "free" en paramètre.
   Note : Le paramètre peut être NULL. */
void tree_free(Tree *t, void (*fun)(void *value));

/** Parcourt un arbre en profondeur et applique une fonction sur chaque noeud. */
/* %param t : Arbre à parcourir. */
/* %param fun : Fonction à appliquer sur chaque noeud de l'arbre : 
   depth correspond à la profondeur courante, 
   value correspond à la valeur retournée. */
void tree_foreach_node(Tree *t, void (*fun)(Tree *node));

/** Calculer la profondeur de chaque noeud de l'arbre courant. */
/* %param TREE : Arbre à parcourir. */
#define tree_calc_depth(TREE) tree_foreach_node(TREE, NULL)

/** Rechercher la racine de l'arbre. */
/* %param t : L'arbre contenant la racine recherchée. */
/* %return : La racine de l'arbre. */
Tree *tree_get_root(Tree *t);

/** Tester si un noeud est la racine d'un arbre. */
/* %param node : Noeud à tester. */
/* %return : true si le noeud est la racine, false sinon. */
bool tree_node_is_root(Tree *node);

/** Tester si un noeud est une feuille d'un arbre. */
/* %param node : Noeud à tester. */
/* %return : true si le noeud est une feuille, false sinon. */
bool tree_node_is_leaf(Tree *node);

/** Obtenir la valeur d'un noeud. */
/* %param node : Le noeud contenant la valeur à récupérer. */
/* %return : La valeur du noeud. */
void *tree_node_get_value(Tree *node);

/** Obtenir la profondeur d'un noeud, racine = 0. */
/* %param node : Le noeud contenant la profondeur à récupérer. */
/* %return : La profondeur du noeud. */
int tree_node_get_depth(Tree *node);

/** Obtenir le père d'un noeud. */
/* %param t : Noeud fils. */
/* %return : NULL si le noeud t est la racine. */
Tree *tree_node_get_father(Tree *t);

/** Insère n noeuds en dessous d'un noeud père à la fin des fils. */
/* %param parent : Noeud père. */
/* %param ... : Noeuds à ajouter, le dernier argument doit être NULL. */
/* %return : NULL en cas d'erreur ou le parent en cas de réussite. */
Tree *tree_add_nodes(Tree *parent,  ...);

/** Insère un noeud en dessous d'un noeud père. */
/* %param parent : Noeud père. */
/* %param pos : Position où doit se trouver le noeud. 
   Si pos < 0, le noeud est ajouté à la fin des fils du noeud père. */
/* %param node : Noeud à ajouter, ne peut être NULL. */
/* %return : Le noeud inseré. */
Tree *tree_node_insert(Tree *parent, int pos, Tree *node);

/** Insère un noeud en dernière position de la liste des fils d'un père. */
/* %param PARENT : Noeud père. */
/* %param NODE : Noeud à ajouter, ne peut être NULL. */
/* %return : Le noeud inseré. */
#define tree_node_append(PARENT, NODE) tree_node_insert(PARENT, -1, NODE)

/** Insère un noeud en première position de la liste des fils d'un père. */
/* %param PARENT : Noeud père. */
/* %param NODE : Noeud à ajouter, ne peut être NULL. */
/* %return : Le noeud inseré. */
#define tree_node_prepend(PARENT, NODE) tree_node_insert(PARENT, 0, NODE)

/** Insére un nouveau noeud en dessous d'un noeud père. */
/* %param PARENT : Noeud père. */
/* %param POS : Position où doit se trouver le noeud. 
   Si pos < 0, le noeud est ajouté à la fin des fils du noeud père. */
/* %param VALUE : Valeur du noeud à ajouter. */
/* %return : Le noeud inseré ou NULL en cas d'erreur d'allocation. */
#define tree_node_insert_value(PARENT, POS, VALUE) \
  tree_node_insert(PARENT, POS, tree_node_new(VALUE))

/** Insère un nouveau noeud en dernière position de la liste des fils d'un père. */
/* %param PARENT : Noeud père. */
/* %param VALUE : Valeur du noeud à ajouter. */
/* %return : Le noeud inseré ou NULL en cas d'erreur d'allocation. */
#define tree_node_append_value(PARENT, VALUE) \
  tree_node_insert(PARENT, -1, tree_node_new(VALUE))
 
/* Insère un nouveau noeud en première position de la liste des fils d'un père. */
/* %param PARENT : Noeud père. */
/* %param VALUE : Valeur du noeud à ajouter. */
/* %return : Le noeud inseré ou NULL en cas d'erreur d'allocation. */
#define tree_node_prepend_value(PARENT, VALUE) \
  tree_node_insert(PARENT, 0, tree_node_new(VALUE))

/* Ajoute un noeud frère à un arbre. */
/* %param origin : Frère d'origine du noeud. */
/* %param brother : Frère à ajouter. */
/* %return : NULL en cas d'erreur ou le frère ajouté en cas de réussite. */
Tree *tree_add_brother(Tree *origin, Tree *brother);

#endif /* _TREE_ INCLUDED */
