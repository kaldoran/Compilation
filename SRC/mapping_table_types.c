/* ---------------------------------------------------------------------- */
/* Filename: mapping_table_types.c                                        */
/* Author: BIGARD Florian                                                 */
/* Date: 2013-10-23 - 14:15:38                                           */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "mapping_table_types.h"

Structure *structure_new(unsigned int field_number, Hashkey hkey)
{
    Structure *s;

    if((s = malloc(sizeof *s)) == NULL)
        return NULL;

    if((s->field = calloc(field_number, sizeof *s->field)) == NULL){
        free(s);
        return NULL;
    }

    s->field_number = field_number;
    s->hkey = hkey;

    return s;
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




