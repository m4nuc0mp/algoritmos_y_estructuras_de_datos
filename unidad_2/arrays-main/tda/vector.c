#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

/**
 * @brief Crea el vector vacío reservando el espacio en memoria. Tamaño = 0, Tamaño Máximo = ini_size.
 * 
 * @param ini_size 
 * @return vector* 
 */
vector* vector_new(int ini_size){
   /*** COMPLETAR ***/
}

/**
 * @brief Eliminar el vector
 * 
 * @param v 
 */
void vector_free(vector* v){
   /*** COMPLETAR ***/ 
} 

/**
 * @brief Permite obtener el tamaño actual del vector
 * 
 * @param v 
 * @return int 
 */
int vector_size(vector* v){
   /*** COMPLETAR ***/
}

/**
 * @brief Devuelve 0 si no está lleno y 1 si está lleno. 
 * 
 * @param v 
 * @return int 
 */
int vector_isfull(vector* v) {
   /*** COMPLETAR ***/
}

/**
 * @brief Devuelve 0 si no está vacío y 1 si está vacío. 
 * 
 * @param v 
 * @return int 
 */
int vector_isempty(vector* v){
   /*** COMPLETAR ***/
}


/**
 * @brief Permite obtener el valor de una posición del vector
 * 
 * @param v 
 * @param index 
 * @return void* 
 */
void* vector_get(vector* v, int index){
   /*** COMPLETAR ***/
}  


/**
 * @brief Permite reemplazar el valor de una posición del vector
 * 
 * @param v 
 * @param index 
 * @return void* 
 */
void* vector_set(vector* v, int index, void* value){
   /*** COMPLETAR ***/
}

/**
 * @brief Permite agregar un elemento al final
 * 
 * @param v 
 * @param value 
 */
int vector_add(vector* v, void* value){
   /*** COMPLETAR ***/
}


/**
 * @brief Permite agregar un elemento en una posición determinada.
 * 
 * @param v 
 * @param index 
 * @param value 
 */
int vector_insert(vector* v, int index, void* value){
   /*** COMPLETAR ***/
}


/**
 * @brief Permite eliminar un elemento del vector
 * 
 * @param v 
 * @param index 
 */
void* vector_remove(vector* v, int index){
   /*** COMPLETAR ***/ 
}

/**
 * @brief print the vector
 * 
 */
void vector_print(vector* v, void (*print)(void*)){
   /*** COMPLETAR ***/
}