#include "cabecera.h"

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