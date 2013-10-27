/* ---------------------------------------------------------------------- */
/* Filename: pile.c                                                       */
/* Author: REYNAUD Nicolas                                                */
/* Date: 2013-10-27 - 14:45:16                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */



#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "ptypes.h"

static unsigned int regions_stack_size = 0;
static Stack_node *start = NULL;

int stack_pop() {
	int val;
	Stack_node *node;
	if(start == NULL) 
		return -1;

	regions_stack_size--;
	node = start;
	start = node->previous;
	val = node->region;
	free(node);
	return val;
}

int stack_top() {
	if(start == NULL) 
		return -1;
	return start->region;
}

void stack_push(int value) {
	Stack_node *new_node = malloc(1*sizeof(*new_node));

	if(new_node == NULL)
		exit(EXIT_FAILURE);
	
	new_node->region = value;
	regions_stack_size++;

	if(start != NULL) 
		new_node->previous = start;
		
	start = new_node;
}

bool stack_is_empty() {
	return regions_stack_size == 0;
}

void stack_free() {
	Stack_node *cur, *next;

	if (start == NULL) 
		return;
	
	for(cur = start; cur != NULL; cur = next) {
		next = cur->previous;
		free(cur);
	}
	start = NULL;
	regions_stack_size = 0;
}
