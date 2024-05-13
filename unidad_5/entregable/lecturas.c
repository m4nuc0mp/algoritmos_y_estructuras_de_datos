/**
 * 
 * Construir un TDA, básico para las lecturas: crear, borrar, obtener minuto,
 * obtener temperatura y comparar.
 * 
 * Hacer una función que simule la creación de la pila con distintas lecturas
 * (lecturas), tomando minutos y temperaturas en forma aleatoria pero coherentes:
 * 
 *      -Los minutos deben ser entre 0 y 1440
 *      -Las temperaturas entre -10 y 40 grados, no debería variar más de 5
 *      grados cada lectura.
 *      -Al menos debe haber entre 20 y 30 lecturas.
 * 
*/

#include "cabecera.h"

lecturas* crear_lectura(int minutos, unidad_temp temp) // void?
{
    lecturas* nueva_medida = NULL;

    nueva_medida->minutos = minutos;
    nueva_medida->temp = temp;
    return nueva_medida;
}

void borrar_lectura(lecturas* basura)
{
    free(basura);
}

int obtener_minutos(lecturas* lectura)
{
    int valor = 0;

    if (NULL != lectura)
    {
        valor = lectura->minutos;
    }
    return valor;
}

unidad_temp obtener_temp(lecturas* lectura)
{
    unidad_temp valor = 0;

    if (NULL != lectura)
    {
        valor = lectura->temp;
    }
    return valor;
}

int comparar_lecturas(lecturas* lectura_1, lecturas* lectura_2)
{
    int resultado = 0;

    if ((NULL != lectura_1) && (NULL != lectura_2))
    {
        if (lectura_1->temp < lectura_2->temp)
        {
            resultado = 1;    
        }
        else if (lectura_1->temp > lectura_2->temp)
        {
            resultado = -1;
        }
        else
        {
            resultado = 0;
        }
    }
    return resultado;
}

pila* generar_pila_aleatoria_temps(int cantidad)
{
    pila* cabecera = NULL;

    if ( (cantidad >= 20) && (cantidad <= 30) )
    {
        for (int contador = 0; contador < cantidad; contador++)
        {
            pila* nodo = crear_nodo_pila()
        }
    }

    return cabecera;
}