/* ---------------------------------------------------------------------- */
/* Filename: syntax_tree.c                                                */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-18 - 09:09:30                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "syntax_tree.h"

void syntax_node_free(void *node)
{
  Syntax_node *n = node;

  if(n->type == AT_CST_STRING)
    free(n->value.s);
  free(n);

  return;
}

void syntax_tree_print_node(Syntax_tree *node)
{
  int i, depth = tree_node_get_depth(node);

  for(i = 0; i < depth; i++)
    printf("   ");
  /* Switch en fonction du numero de noeud.*/
  												/* NEED VRAIE FONCTION */
  switch ((int)&tree_node_get_value(node)) {
  	case 1: 
  		print("");
  	break;
  	case 2: 
  		print("");
  	break;
  	case 3: 
  		print("");
  	break;
  	case 4: 
  		print("");
  	break;
  	case 5: 
  		print("");
  	break;
  	case 6: 
  		print("");
  	break;
  	case 7: 
  		print("");
  	break;
  	case 8: 
  		print("");
  	break;
  	case 9: 
  		print("");
  	break;
  	case 10: 
  		print("");
  	break;
  	case 11: 
  		print("");
  	break;
  	case 12: 
  		print("");
  	break;
  	case 13: 	
  		print("");
  	break;
  	case 14: 
  		print("");
  	break;
  	case 15: 
  		print("");
  	break;
  	case 16: 
  		print("");
  	break;
  	case 17: 
  		print("");
  	break;
  	case 18: 
  		print("");
  	break;
  	case 19: 
  		print("");
  	break;
  	case 20: 
  		print("");
  	break;
  	case 21: 
  		print("");
  	break;
  	case 22: 
  		print("");
  	break;
  	case 23: 
  		print("");
  	break;
  	case 24: 
  		print("");
  	break;
  	case 25:  
  		print("");
  	break;
  	case 26:  
  		print("");
  	break;
  	case 27:  
  		print("");
  	break;
  	case 28:  
  		print("");
  	break;
  	case 29:  
  		print("");
  	break;
  	case 30:  
  		print("");
  	break;
  	case 31:  
  		print("");
  	break;
  	default: 
  		print("UNKNOWN");
     break;
  }
  /* Contenu adresse printf("%p\n", tree_node_get_value(node)); */

  return;
}

