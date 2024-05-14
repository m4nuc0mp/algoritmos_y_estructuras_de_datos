#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

////////////////////////////////////////////////////////////////////////////////
//////////////////////// TDA BASICO DE LECTURAS ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define temp_unit int32_t
typedef struct _reading
{
    int32_t min;
    temp_unit temp;
} reading;

reading* reading_create(int32_t min, temp_unit temp);

void reading_delete(reading* re);

int32_t reading_get_minute(reading* re);

temp_unit reading_get_temp(reading* re);

int8_t reading_cmp(reading* re_1, reading* re_2);

////////////////////////////////////////////////////////////////////////////////
//////////////////////// PILA DE VARIAS DE LECTURAS ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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

stack* temp_stack_simulation(int32_t max_time, int32_t temp_min,
    int32_t temp_max, int32_t step, int64_t nex);

////////////////////////////////////////////////////////////////////////////////
/////////////////// LISTA DINAMICA DE PILAS DE LECTURAS ////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define list_elem stack*

typedef struct _sll_node
{
    list_elem value;
    struct _sll_node* next;
} sll_node;

sll_node* sll_new_node(list_elem element);

sll_node* sll_add_node(sll_node** head, sll_node* new_node);

sll_node* sll_temp_stacks_simulation(
    int32_t max_time, int32_t temp_min, int32_t temp_max, int32_t step,
    int64_t nex, int64_t nsll
    );

int64_t rand_times(int64_t lower, int64_t upper);

int32_t rand_time(int32_t min_time, int32_t max_time);

int32_t rand_temp(temp_unit min_temp, temp_unit max_temp, temp_unit step);

////////////////////////////////////////////////////////////////////////////////
///////////////////// ARBOLES BINARIOS Y DE BUSQUEDA ///////////////////////////
////////////////////////////////////////////////////////////////////////////////


// ARBOLES BINARIOS

#define t_elem_btree reading

typedef struct _btn {
    t_elem_btree value;
    struct _btn *left;
    struct _btn *right;
} btn;

btn* btn_new(t_elem_btree value);

void btn_free(btn** node);

btn** btn_find(
    btn** node, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree));

int btn_isLeaf(btn *node);

int btn_count(btn *node);

int btn_insert(btn **node, btn *newNode);

int btn_insert_value(btn **node, int value);

int _btn_level(
    btn *node, t_elem_btree value,
    int level, int cmp(t_elem_btree, t_elem_btree));

int btn_level(
    btn* root, t_elem_btree value, int cmp(t_elem_btree, t_elem_btree));

int cmp(t_elem_btree value_a, t_elem_btree value_b);

int _max(int a, int b);

t_elem_btree btn_height(btn *node);

void btn_inorder(btn *node, void btn_do(btn*, void*), void* ctx);

void btn_postorder(btn *node, void btn_do(btn*, void*), void* ctx);

void btn_preorder(btn *node, void btn_do(btn*, void*), void* ctx);

int _btn_print(
    btn *tree, int is_left, int offset, int depth,
    char s[20][255], void toStr (btn*, char*));

void btn_print(btn *tree, void toStr (btn*, char*));

// ARBOLES BINARIOS DE BUSQUEDA

t_elem_btree _max_elem (
    t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree));

int sbt_insert_node(
    btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree));

int sbt_insert_value(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_get_min_node(btn **node);

t_elem_btree sbt_min(btn *node);

btn** sbt_get_max_node(btn **node);

t_elem_btree sbt_get_max_value(btn *node);

btn* sbt_findr(
    btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn *sbt_findi(
    btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_find_node(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn** sbt_findii(
    btn** node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_in(
    btn* node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

btn* sbt_remove_node(btn **node,  int cmp (t_elem_btree, t_elem_btree));

btn* sbt_remove_node2(btn **node);

btn *sbt_remove_node_smart(btn **node);

int sbt_remove_value(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_remove_value2(
    btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree));

int sbt_remove_value_smart(
    btn **node, int value, int cmp (t_elem_btree, t_elem_btree));



////////////////////////////////////////////////////////////////////////////////
/////////////////////// COLA DE MEDICIONES ORDENADAS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

#define queue_elem stack*

typedef struct _queue
{
    queue_elem value;
    struct _queue* prev;
    struct _queue* next;
} queue;

queue* queue_new_node(queue_elem element);

void queue_enqueue(queue** head, queue_elem element);

queue* queue_dequeue(queue** head);

int test_temps_sorting(queue* temps);

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// FUNCION SOLICITADA /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

queue* make_sorted_temp_queue(btn* sll_temp_stacks);

#endif // CABECERA_H_INCLUDED