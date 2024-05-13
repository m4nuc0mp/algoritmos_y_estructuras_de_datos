#ifndef TEMP_H_INCLUDED
#define TEMP_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define unidad_temp int32_t

/**
 * Construir un TDA, básico para las lecturas: crear, borrar, obtener minuto,
 * obtener temperatura y comparar.
 * 
*/

typedef struct
{
    int minutos;
    unidad_temp temp;
} lecturas;

lecturas* crear_lectura(int minutos, unidad_temp temp);
void borrar_lectura(lecturas* basura);
int obtener_minutos(lecturas* lectura);
unidad_temp obtener_temp(lecturas* lectura);
int comparar_lecturas(lecturas* lectura_1, lecturas* lectura_2);

#endif