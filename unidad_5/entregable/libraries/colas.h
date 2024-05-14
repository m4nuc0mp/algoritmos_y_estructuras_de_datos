#ifndef COLAS_H_INCLUDED
#define COLAS_H_INCLUDED

#include "../cabecera.h"

#define queue_elem stack*

typedef struct _queue
{
    queue_elem value;
    struct _queue* prev;
    struct _queue* next;
} queue;

queue* queue_new_node(queue_elem element);
int8_t queue_enqueue(queue* some_queue, queue_elem element);
queue* queue_dequeue(queue* some_queue);

#endif // COLAS_H_INCLUDED