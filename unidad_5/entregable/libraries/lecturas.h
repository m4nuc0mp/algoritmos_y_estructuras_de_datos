#ifndef LECTURAS_H_INCLUDED
#define LECTURAS_H_INCLUDED

#include "cabecera.h"

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
int8_t reading_cmp(reading* re_1, reading re_2);

#endif  // LECTURAS_H_INCLUDED