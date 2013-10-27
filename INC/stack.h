/* ---------------------------------------------------------------------- */
/* Filename: stack.h                                                      */
/* Author: REYNAUD Nicolas                                                */
/* Date: 2013-10-27 - 14:38:27                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */
	
#include "ptypes.h"

/** Structure d'un noeud de la pile */
typedef struct Stack_node {
	int region;
	struct Stack_node *previous;
} Stack_node;

/** Retourne le sommet de pile en le depilant */
/* %return : Le sommet de pile. */
int stack_pop();

/** Retourne le sommet de pile sans le depiler */
/* %return : Le sommet de pile. */
int stack_top();

/** Retourne le sommet de pile en le depilant */
/* %param l : La liste contenant le nombre d'éléments à récupérer. */
void stack_push(int value);

/** Teste si la pile est vide. */
/* %return : true si la pile est vide, false sinon. */
bool stack_is_empty();

/** Libère complètement une pile. */
void stack_free();

