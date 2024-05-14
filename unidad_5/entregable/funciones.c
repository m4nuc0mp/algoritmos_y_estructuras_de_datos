#include "cabecera.h"

////////////////////////////////////////////////////////////////////////////////
//////////////////////// TDA BASICO DE LECTURAS ////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

reading* reading_create(int32_t min, temp_unit temp)
{
    reading* new_reading = (reading*) malloc(sizeof(reading));

    if (NULL != new_reading)
    {
        new_reading->min = min;
        new_reading->temp = temp;
    }
    return new_reading;
}

void reading_delete(reading* re)
{
    free(re);
}

int32_t reading_get_minute(reading* re)
{
    int32_t time = -1;

    if (NULL != re)
    {
        time = re->min;
    }
    return time;
}

temp_unit reading_get_temp(reading* re)
{
    int32_t temp = -274;

    if (NULL != re)
    {
        temp = re->temp;
    }
    return temp;
}

int8_t reading_cmp(reading* re_1, reading* re_2)
{
    int8_t result = 0;

    if (re_1->temp < re_2->temp)
    {
        result = -1;
    }
    else if (re_1->temp > re_2->temp)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////// PILA DE VARIAS DE LECTURAS ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

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

stack* temp_stack_simulation(
    int32_t max_time, int32_t temp_min,
    int32_t temp_max, int32_t step, int64_t nex
    )
{

    stack* readings_stack = stack_create(nex);
    
    for (int64_t counter = 0; counter < nex; counter++)
    {
        stack_push(
            readings_stack,
            *(
                reading_create(
                    rand_time(0, max_time),
                    rand_temp(temp_min, temp_max, step)
                )
            )
        );
    }

    return readings_stack;
}

////////////////////////////////////////////////////////////////////////////////
/////////////////// LISTA DINAMICA DE PILAS DE LECTURAS ////////////////////////
////////////////////////////////////////////////////////////////////////////////

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

sll_node* sll_temp_stacks_simulation(
    int32_t max_time, int32_t temp_min, int32_t temp_max, int32_t step,
    int64_t nex, int64_t nsll
    )
{
    sll_node* head = NULL;
    sll_node* aux = NULL;

    for (int64_t counter = 0; counter < nsll; counter++)
    {
        aux = sll_new_node(
            temp_stack_simulation(max_time, temp_min, temp_max, step, nex)
            );
        
        sll_add_node(&head, aux);
    }
    return head;
}

int64_t rand_times(int64_t lower, int64_t upper)
{
    return (rand() % (upper - lower)) + lower;
}

int32_t rand_time(int32_t min_time, int32_t max_time)
{
    return (rand() % (max_time - min_time)) + min_time;
}

int32_t rand_temp(temp_unit min_temp, temp_unit max_temp, temp_unit step)
{
    temp_unit rnd_temp = (rand() % (max_temp - min_temp)) + min_temp;

    if ((0 != rnd_temp % step) || (rnd_temp < -273))
    {
        rnd_temp = rand_temp(min_temp, max_temp, step);
    }
    return rnd_temp;
}

////////////////////////////////////////////////////////////////////////////////
///////////////////// ARBOLES BINARIOS Y DE BUSQUEDA ///////////////////////////
////////////////////////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////////////////////////
/////////////////////// COLA DE MEDICIONES ORDENADAS ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

queue* queue_new_node(queue_elem element)
{
    queue* new_queue_node = (queue*) malloc(sizeof(queue_elem));

    if (NULL != new_queue_node)
    {
        new_queue_node->value = element;
        new_queue_node->prev = NULL;
        new_queue_node->next = NULL;
    }
    return new_queue_node;
}

void queue_enqueue(queue** head, queue_elem element)
{
    if (NULL != element)
    {
        while (NULL != (*head)->prev)
        {
            head = (*head)->prev;
        }
        queue* new_node = queue_new_node(element);

        new_node->next = (*head)->prev;
    }
}

queue* queue_dequeue(queue** head)
{
    while (NULL != (*head)->next)
    {
        head = (*head)->next;
    }
    queue* aux = *head;

    // Retroceder
    head = (*head)->prev;

    // Cerrar la queue al final
    (*head)->next = NULL;

    return aux;
}

int test_temps_sorting(queue* temps)
{

}

////////////////////////////////////////////////////////////////////////////////
/////////////////////////// FUNCION SOLICITADA /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

queue* make_sorted_temp_queue(btn* sll_temp_stacks)
{

}