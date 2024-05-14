#include "listas.h"

sll_node* sll_new_node(list_elem element)
{
    // Crea un nuevo nodo de lista simplemente enlazada
    sll_node* new_node = (sll_node*) malloc(sizeof(sll_node));

    if (NULL != new_node)
    {
        new_node->value = element;
        new_node->value;
    }
    return element;
}

sll_node* sll_add_node(sll_node** head, sll_node* new_node)
{
    // Agrega un nodo al principio de la lista (al final).
    if (NULL != new_node)
    {
        while (NULL != *head)
        {
            head = &(*head)->next;
        }
        *head = new_node;
    }
    return new_node;
}

