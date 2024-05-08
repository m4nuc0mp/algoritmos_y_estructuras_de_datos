#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

typedef struct _num_matrix num_matrix; //num_matrix is a struct that contains a matrix


/**
 * @brief Crea la matriz con el tamaño apropiado según las dimensiones establecidas.
 * 
 * @param row filas 
 * @param col columnaumns 
 * @return num_matrix* 
 */
num_matrix* num_matrix_new(int rows, int columns){
    /*** COMPLETAR ***/
}

/**
 * @brief Elimina la matriz
 * 
 * @param m puntero a la matriz 
 */
void num_matrix_free(num_matrix* m){
    /*** COMPLETAR ***/
}

/**
 * @brief Permite obtener la cantidad de filas
 * 
 * @param m puntero a la matriz 
 * @return int la cantidad de filas
 */
int num_matrix_rows(num_matrix* m){
    /*** COMPLETAR ***/    
}

/**
 * @brief Permite obtener la cantidad de columnas
 * 
 * @param m puntero a la matriz 
 * @return int la cantidad de columnas
 */
int num_matrix_columns(num_matrix* m){
   /*** COMPLETAR ***/
}

/**
 * @brief Permite obtener el valor de una posición de la matriz
 * 
 * @param m puntero a la matriz 
 * @param row fila 
 * @param col columna 
 * @return float 
 */
float num_matrix_get(num_matrix* m, int row, int col){
    /*** COMPLETAR ***/
}

/**
 * @brief Permite reemplazar o asignar un elemento a la matriz
 * 
 * @param m puntero a la matriz 
 * @param row fila
 * @param col columna
 * @param value valor a asignar
 */
void num_matrix_set(num_matrix* m, int row, int col, float value){
    /*** COMPLETAR ***/
}


void _print_float (void* value){
   /*** COMPLETAR ***/
}

/**
 * @brief Permite imprimir una matriz por consola
 * 
 * @param m puntero a la matriz 
 * @param prt función que permite imprimir un valor de la matriz
 */
void num_matrix_print(num_matrix* m){
    //matrix_print(m->m, _print_float);
}