#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

#include "../cabecera.h"

#define list_elem stack*

typedef struct _sll_node
{
    list_elem value;
    struct _sll_node* next;
} sll_node;

sll_node* sll_new_node(list_elem element);
int8_t sll_add_node(sll_node** head, sll_node* new_node);

#endif  // LISTAS_H_INCLUDED