#include "pilas.h"

stack_node* stack_node_create(elem_type elem)
{
    stack_node* new_node = (stack_node*) malloc(sizeof(stack_node));

    if (NULL != new_node)
    {
        new_node->value = elem;
        new_node->next = NULL;
    }
    return new_node;
}

stack* stack_create(int64_t init_size)
{
    stack* new_stack = (stack*) malloc(sizeof(stack));

    if (NULL != new_stack)
    {
        new_stack->head = NULL;
        new_stack->count = 0;
        new_stack->max_size = init_size;
    }
    return new_stack;
}

void stack_free(stack* trash)
{
    stack_node* aux = NULL;

    while (NULL != trash->head)
    {
        aux = trash->head;
        trash->head = trash->head->next;
        free(aux);
    }
    free(trash);
}

int64_t stack_get_size(stack* some_stack)
{
    int64_t stack_size = 0;

    if (NULL != some_stack)
    {
        stack_size = some_stack->count;    
    }
    else
    {
        stack_size = -1;
    }
    return stack_size;
}

int64_t stack_get_max_size(stack* some_stack)
{
    if (some_stack->max_size == stack_get_size(some_stack))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void stack_push(stack* some_stack, elem_type elem)
{
    stack_node* new_node = stack_node_create(elem);

    if ((NULL != new_node) && (!stack_is_full(some_stack)))
    {
        new_node->next = some_stack->head;
        some_stack->count++;
        some_stack->head->next = new_node;
    }
}

stack_node* pop(stack* some_stack)
{
    stack_node* aux = NULL;

    if (!stack_is_empty(some_stack))
    {
        aux = some_stack->head;
        some_stack->head = some_stack->head->next;
        some_stack->count--;
        aux->next = NULL;
    }
    return aux;
}

elem_type stack_top(stack* some_stack)
{
    if ((!stack_is_empty(some_stack)) && (NULL != some_stack))
    {
        return some_stack->head->value;    
    }    
}

int8_t stack_is_empty(stack* some_stack)
{
    int8_t is_empty = 0;
    
    if (0 == some_stack->count)
    {
        is_empty = 1;
    }
    else
    {
        is_empty = 0;
    }
    return is_empty;
}

int8_t stack_is_full(stack* some_stack)
{
    int8_t is_full = 0;
    
    if (0 == some_stack->count)
    {
        is_full = 1;
    }
    else
    {
        is_full = 0;
    }
    return is_full;
}

