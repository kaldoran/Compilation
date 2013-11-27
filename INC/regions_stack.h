/* ---------------------------------------------------------------------- */
/* Filename: regions_stack.h                                              */
/* Author: ABHAMON Ronan, BIGARD Florian, REYNAUD Nicolas                 */
/* Date: 2013-10-27 - 17:34:07                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#ifndef _REGIONS_STACK_
#define _REGIONS_STACK_

/** Un élément de la pile. */
typedef struct Region_node
{
  int region;               /* Numéro de région. */
  struct Region_node *next; /* Région suivante. */
} Region_node;

/** Libère la pile des régions. */
void regions_stack_free(void);

/** Ajoute un numéro de région dans la pile interne. */
/* %param region : Numéro de la région à ajouter. */
/* %return : -1 en cas d'erreur d'allocation ou le numéro de la région ajoutée. */
int regions_stack_push(int region);

/** Dépile une région de la pile. */
/* %return : -1 si pile vide ou le numéro de la région dépilée sinon. */
int regions_stack_pop(void);

/** Retourne le numéro de la région en sommet de pile. */
/* %return : -1 si pile vide ou le numéro de la région du sommet de pile sinon. */
int regions_stack_top(void);

/** Obtenir la taille de la pile des régions. */
/* %return : Taille de la pile. */
unsigned int regions_stack_get_size(void);

/** Obtenir le premier noeud de la pile. */
/* %return : NULL si pile vide ou le noeud sinon. */
Region_node *regions_stack_get_node(void);

#endif /* _REGIONS_STACK_ INCLUDED */
