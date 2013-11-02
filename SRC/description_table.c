/* ---------------------------------------------------------------------- */
/* Filename: description_table.c                                          */
/* Author: BIGARD Florian                                                 */
/* Date: 2013-10-23 - 14:15:38                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "description_table.h"

Structure *structure_new(unsigned int field_number)
{
  Structure *s;

  if((s = malloc(sizeof *s)) == NULL)
    return NULL;

  if((s->field = calloc(field_number, sizeof *s->field)) == NULL)
  {
    free(s);
    return NULL;
  }

  s->field_number = field_number;

  return s;
}

void structure_free(Structure *s)
{
  if(s == NULL)
    return;

  free(s->field);
  free(s);

  return;
}

Array *array_new(unsigned int dimension_number, Index_t type)
{
  Array *a;

  if((a = malloc(sizeof *a)) == NULL)
    return NULL;

  if((a->dimension = calloc(dimension_number, sizeof *a->dimension)) == NULL)
  {
    free(a);
    return NULL;
  }

  a->dimension_number = dimension_number;
  a->type = type;
    
  return a;
}

void array_free(Array *a)
{
  if(a == NULL)
    return;

  free(a->dimension);
  free(a);

  return;
}

Function *function_new(Index_t return_type, unsigned int param_number)
{
  Function *f;

  if((f = malloc(sizeof *f)) == NULL)
    return NULL;

  if((f->params = calloc(param_number, sizeof *f->params)) == NULL)
  {
    free(f);
    return NULL;
  }

  f->return_type = return_type;
  f->param_number = param_number;

  return f;
}

void function_free(Function *f)
{
  if(f == NULL)
    return;

  free(f->params);
  free(f);

  return;
}

Procedure *procedure_new(unsigned int param_number)
{
  Procedure *p;

  if((p = malloc(sizeof *p)) == NULL)
    return NULL;

  if((p->params = calloc(param_number, sizeof *p->params)) == NULL)
  {
    free(p);
    return NULL;
  }

  p->param_number = param_number;

  return p;
}

void procedure_free(Procedure *p)
{
  if(p == NULL)
    return;

  free(p->params);
  free(p);

  return;
}

void structure_print(Structure *structure) 
{
  unsigned int i;

  printf("\n\tStructure (%d)\n", structure->field_number);

  for(i = 0; i < structure->field_number; i++) 
    printf("\t   [%d] Key : %p - Index : %p\n", i, structure->field[i].hkey, 
           structure->field[i].type);

  printf("\tEnd structure\n    ");

  return;
}

void procedure_print(Procedure *procedure) 
{
  unsigned int i;
        
  printf("\n\tProcedure (%d)\n", procedure->param_number);
        
  for(i = 0; i < procedure->param_number; i++) 
    printf("\t   [%d] Key : %p - Index : %p\n", i, procedure->params[i].hkey,
           procedure->params[i].type);
                
  printf("\tEnd procedure\n    ");
        
  return;
}

void function_print(Function *function) 
{
  unsigned int i;
        
  printf("\n\tFunction (%d) - Return (%p)\n", function->param_number, function->return_type);
        
  for(i = 0; i < function->param_number; i++) 
    printf("\t   [%d] Key : %p - Index : %p\n", i, function->params[i].hkey,
           function->params[i].type);
                
  printf("\tEnd function\n    ");
        
  return;
}

void array_print(Array *array) 
{
  unsigned int i;
        
  printf("\n\tArray (%d) - Type (%p)\n", array->dimension_number,array->type);
        
  for (i = 0; i < array->dimension_number; i++) 
    printf("\t   [%d] Start : %d - End : %d (%d)\n", i, array->dimension[i].bound_lower,
           array->dimension[i].bound_upper,
           array->dimension[i].bound_upper - array->dimension[i].bound_lower );
                
  printf("\tEnd array\n    ");
        
  return;
}
