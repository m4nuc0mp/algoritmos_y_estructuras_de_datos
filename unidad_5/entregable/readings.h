#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define temp_unit int32_t

/**
 * Construir un TDA, básico para las lecturas: crear, borrar, obtener minuto,
 * obtener temperatura y comparar.
 * 
*/

typedef struct
{
    int minute;
    temp_unit temperature;
} reading;

reading* reading_create(void);
void reading_delete(reading* trash);
int get_minute(reading* r);
temp_unit get_temp(reading* r);
int cmp_readings(reading* r1, reading* r2);

#endif