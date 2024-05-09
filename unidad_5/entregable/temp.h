#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define temp_unit int32_t
#define t_element_stck temp_unit
#define t_element_sll uint64_t

typedef struct
{
    int minute;
    temp_unit temperature;
} reading;

typedef struct _stack
{
    t_element_stck value;
    struct _stack* next;
    int64_t top;
} stack;

typedef struct _sll
{
    t_element_sll value;
    struct _sll* next;
} sll;


int store_temp_measures(stack** sensor_stack, int x_minutes);
int record_daily_measures(s)

#endif