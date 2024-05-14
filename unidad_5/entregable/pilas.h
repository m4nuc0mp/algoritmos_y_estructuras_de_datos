#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "cabecera.h"

#define elem_type reading

typedef struct _stack_node
{
    elem_type value;
    struct _stack* next;
} stack_node;

typedef struct _stack
{
    stack_node* head;
    int64_t max_size;
    int64_t count;
} stack;

stack_node* stack_node_create(elem_type elem);
stack* stack_create(int64_t init_size);
void stack_free(stack* trash);
int64_t stack_get_size(stack* some_stack);
int64_t stack_get_max_size(stack* some_stack);
void stack_push(stack* some_stack, elem_type elem);
stack_node* pop(stack* some_stack);
elem_type stack_top(stack* some_stack);
int8_t stack_is_empty(stack* some_stack);
int8_t stack_is_full(stack* some_stack);

#endif // PILAS_H_INCLUDED