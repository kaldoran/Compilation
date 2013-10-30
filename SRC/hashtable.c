/* ---------------------------------------------------------------------- */
/* Filename: hashtable.c                                                  */
/* Author: ABHAMON Ronan                                                  */
/* Date: 2013-09-09 - 19:09:04                                            */
/*                                                                        */
/* ---------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "private_list.h"
#include "list.h"
#include "private_hashtable.h"
#include "hashtable.h"  
#include "error.h"

/* ---------------------------------------------------------------------- */
/* Fonctions internes (privées)                                           */
/* ---------------------------------------------------------------------- */

/** Alloue et initialise une structure Hashvalue. */
/* %param id : Id (chaine) servant à générer la clef de Hachage. */
/* %param value : Valeur à stocker. */
/* %return : Une structure Hashvalue initialisée ou NULL en cas d'échec. */
static Hashvalue *hashvalue_new(const char *id, void *value);

/** Libère complètement une structure Hashvalue. */
/* %param hvalue : La Hashvalue à libérer. */
/* %param fun : Agit sur la valeur contenue dans la Hashvalue. 
   Pour un usage classique, utiliser "free" en paramètre.
   Note : Le paramètre peut être NULL. */
static void hashvalue_free(Hashvalue *hvalue, void (*fun)(void *value));

/* ---------------------------------------------------------------------- */

static Hashvalue *hashvalue_new(const char *id, void *value)
{
  Hashvalue *hvalue;
  char *id_new = NULL;
  size_t len = strlen(id);

  if((hvalue = malloc(sizeof *hvalue)) == NULL ||
     (id_new = malloc((len + 1) * sizeof *id_new)) == NULL)
  {
    free(id_new);
    return NULL; /* Bad alloc */
  }
  
  strcpy(id_new, id);
  hvalue->id = id_new;
  hvalue->len = len;
  hvalue->value = value;

  return hvalue;
}

static void hashvalue_free(Hashvalue *hvalue, void (*fun)(void *value))
{
  if(hvalue == NULL)
    return;

  free(hvalue->id);

  if(fun != NULL)
    fun(hvalue->value);

  free(hvalue);

  return;
}

/* ---------------------------------------------------------------------- */

Hashtable *hashtable_new_with_size(size_t size)
{
  Hashtable *h;
 
  if((h = calloc(1, sizeof *h)) == NULL ||
     (h->array = calloc(size, sizeof *h->array)) == NULL ||
     (h->hvalues = list_new()) == NULL)
  {
    free(h->hvalues);
    free(h->array);
    free(h);

    return NULL; /* Bad alloc */
  }

  h->size = 0;
  h->size_max = size;

  return h;
}

void hashtable_free(Hashtable *h, void (*fun)(void *value))
{
  unsigned int i;
  List_node *cur, *next;

  if(h == NULL)
    return;

  for(i = 0; i < h->size_max; i++)
    if(h->array[i] != NULL)
    {
      for(cur = h->array[i]->start; cur != NULL; cur = next)
      {
        next = cur->next;
        hashvalue_free(cur->value, fun);
        free(cur);
      }
  
      free(h->array[i]);
    }
  
  list_free(h->hvalues, NULL);
  free(h->array);
  free(h);

  return;
}

Hashtable *hashtable_resize(Hashtable *h, size_t size)
{
  Hashtable *h_new;
  List_node *cur, *next;
  unsigned int i;

  if(h == NULL || (h_new = hashtable_new_with_size(size)) == NULL)
    return NULL;

  for(i = 0; i < h->size_max; i++)
    if(h->array[i] != NULL)
    {
      for(cur = h->array[i]->start; cur != NULL; cur = next)
      {
        /* Si erreur d'allocation */
        if(hashtable_add_value(h_new, HNVALUE(cur)->id, HNVALUE(cur)->value) == NULL)
          fatal_error("hashtable_resize");

        next = cur->next;
        hashvalue_free(cur->value, NULL);
        free(cur);
      }

      free(h->array[i]);
    }

  free(h->array);
  h->array = h_new->array;
  h->size_max = h_new->size_max;
  free(h_new);

  return h;
}

unsigned int hashtable_get_size(Hashtable *h)
{
  return h->size;
}

unsigned int hashtable_get_size_max(Hashtable *h)
{
  return h->size_max;
}

const char *hashtable_get_id(Hashtable *h, Hashkey hkey)
{
  (void)h;
  return ((Hashvalue *)hkey)->id;
}

Hashkey hashtable_get_key(Hashtable *h, const char *id)
{
  List *l;
  List_node *ln;
  unsigned int index = HCODE(h, id);
 
  if((l = h->array[index]) != NULL)
    for(ln = l->start; ln != NULL; ln = ln->next)
      if(strcmp(HNVALUE(ln)->id, id) == 0)
        return ln->value;

   return NULL; /* Elément non trouvé */
}

void *hashtable_get_value_by_id(Hashtable *h, const char *id)
{
  List *l;
  List_node *ln;
  unsigned int index = HCODE(h, id);

   if((l = h->array[index]) != NULL)
     for(ln = l->start; ln != NULL; ln = ln->next)
       if(strcmp(HNVALUE(ln)->id, id) == 0)
         return HNVALUE(ln)->value;

   return NULL; /* Elément non trouvé */
}

void *hashtable_get_value_by_key(Hashtable *h, Hashkey hkey)
{  
  (void)h;
  return ((Hashvalue *)hkey)->value;
}

bool hashtable_set_value_by_id(Hashtable *h, const char *id, void *value)
{
  List *l;
  List_node *ln;
  unsigned int index = HCODE(h, id);

   if((l = h->array[index]) != NULL)
     for(ln = l->start; ln != NULL; ln = ln->next)
       if(strcmp(HNVALUE(ln)->id, id) == 0)
       {
         HNVALUE(ln)->value = value;
         return true;
       }

   return false; /* Elément non trouvé */
}

bool hashtable_set_value_by_key(Hashtable *h, Hashkey hkey, void *value)
{
  (void)h;
  if(hkey == NULL) return false;
  ((Hashvalue *)hkey)->value = value;
  return true;
}

Hashkey hashtable_exists_id(Hashtable *h, const char *id)
{
  List_node *ln;
  List *l;
  unsigned int index = HCODE(h, id);
  unsigned char i = 0;
  
  if((l = h->array[index]) != NULL) 
    for(ln = l->start; ln != NULL; ln = ln->next, i++)
      if(strcmp(HNVALUE(ln)->id, id) == 0)
        return ln->value;
  
  return NULL;
}

Hashkey hashtable_add_value(Hashtable *h, const char *id, void *value)
{
  Hashvalue *hvalue;
  List *l = NULL;

  /* Récupération du code entier de la chaine */
  unsigned int index = HCODE(h, id);

  /* Si chaine linéaire vide... */
  if((l = h->array[index]) == NULL)
  {
    if((l = list_new()) == NULL)
       fatal_error("hashtable_add_value");

    h->array[index] = l;
  }
  
  /* Vérification de l'inexistence de la chaine */
  if((hvalue = hashtable_exists_id(h, id)) != NULL)
    return hvalue;

  /* Création de la Hashvalue */
  /* Ajout de la valeur */
  if((hvalue = hashvalue_new(id, value)) == NULL ||
     list_push_node(l, hvalue) == NULL)
    fatal_error("hashtable_add_value");

  /* Mise à jour de la liste des valeurs */
  if(list_push_node(h->hvalues, hvalue) == NULL)  
    fatal_error("hashtable_add_value");

  h->size++;

  return hvalue;
}
 
void hashtable_foreach_key(Hashtable *h, void (*fun)(const char *key, void *value), void *value)
{
  List_node *ln;

  for(ln = h->hvalues->start; ln != NULL; ln = ln->next)
    fun(HNVALUE(ln)->id, value);

  return;
}

void hashtable_foreach_value(Hashtable *h, void (*fun)(void *value, void *cvalue), void *cvalue)
{
  List_node *ln;

  for(ln = h->hvalues->start; ln != NULL; ln = ln->next)
    fun(HNVALUE(ln)->value, cvalue);

  return;
}

void hashtable_print(Hashtable *h, void (*fun)(void *value))
{
  List_node *ln;

  /* Parcours de la liste des hvalues */
  for(ln = h->hvalues->start; ln != NULL; ln = ln->next)
  {
    printf("Key: \"%s\" (%lu)", HNVALUE(ln)->id, (long unsigned int)HNVALUE(ln)->len);
    fun == NULL ? (void)printf("\n") : fun(HNVALUE(ln)->value);
  }

  return;
}

Hashcode hashcode(const char *str)
{ 
  char *ptr = (char *)str;
  Hashcode res = 0;

  /* Hachage cyclique, optimisé pour les mots anglais */
  for(; *ptr != '\0'; ptr++)
  {
    res = (res << 5) | (res >> 27);
    res += *ptr;
  }

  return res;
}
