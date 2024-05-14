#ifndef CABECERA_H_INCLUDED
#define CABECERA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "lecturas.h"
#include "pilas.h"
#include "listas.h"

stack* temp_stack_simulation(int32_t max_time, int32_t temp_min,
    int32_t temp_max, int32_t step, int64_t nex);

sll_node* sll_temp_stacks_simulation(
    int32_t max_time, int32_t temp_min, int32_t temp_max, int32_t step,
    int64_t nex, int64_t nsll
    );

int64_t rand_times(int64_t lower, int64_t upper);
int32_t rand_time(int32_t min_time, int32_t max_time);
int32_t rand_temp(temp_unit min_temp, temp_unit max_temp, temp_unit step);

#endif // CABECERA_H_INCLUDED