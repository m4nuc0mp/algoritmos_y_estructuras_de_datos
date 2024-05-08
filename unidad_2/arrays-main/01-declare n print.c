#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lib/array_search.h"

/**
 * @brief Imprime el contenido de un arreglo de enteros
 *
 * @param a arreglo de enteros
 * @param n tamaño
 */
void print_contenido_1(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("A[%d] = %d\n", i, a[i]);
    }
}

/**
 * @brief Imprime el contenido de un arreglo de enteros
 * pasado como puntero
 *
 * @param a puntero a enteros
 * @param n cantidad de elementos
 */
void print_contenido_2(int* a, int n) {
    for (int* f = a + n; a < f; a++) {
        printf("A[%d] = %d\n", (n - (f - a)), *a);
    }
}

/**
 * @brief Imprime el contenido de un arreglo de caracteres
 * cadena de caracteres (String) debe finalizar con \0
 *
 * @param cadena arreglo de caracteres
 */
void print_cadena_1(char cadena[]) {
    int n = strlen(cadena);
    for (int i = 0; i < n; i++) {
        printf("Cadena[%d] = %c\n", i, cadena[i]);
    }
}

/**
 * @brief Imprime el contenido de un arreglo de caracteres
 * cadena de caracteres (String) debe finalizar con \0
 * pasado como un puntero a char
 *
 * @param cadena puntero a char (arreglo de caracteres - string)
 */
void print_cadena_2(char* cadena) {
    int i = 0;
    while (*cadena != '\0') {
        printf("Cadena[%d] = %c\n", i++, *cadena);
        cadena++;
    }
}

void main() {
    // Declara un arreglo de enteros
    int arreglo_enteros[100];

    // Asignación de valores
    arreglo_enteros[0] = -1;
    arreglo_enteros[1] = -2;
    arreglo_enteros[2] = -3;

    // Declaración y Asignación
    int arreglo_ejemplo[] = {1, 2, 3, 4, 5, 6};

    // Impresión de contenido
    printf("\nArreglo de enteros\n");
    print_contenido_1(arreglo_enteros, 3);

    printf("\nArreglo de ejemplo\n");
    print_contenido_1(arreglo_ejemplo, 6);

    // Búsqueda secuencial 
    int pos = sequential_search(3, arreglo_ejemplo, 6);
    if (pos >= 0){
        printf("El valor 3 se encuentra en la posición %d\n", pos);
    } else {
        printf("El valor 3 no se encuentra en el arreglo\n");
    }

    pos = sequential_search(7, arreglo_ejemplo, 6);
    if (pos >= 0){
        printf("El valor 7 se encuentra en la posición %d\n", pos);
    } else {
        printf("El valor 7 no se encuentra en el arreglo\n");
    }


    /*

    // Declaración como un puntero
    int* arreglo_puntero;
    int* pos;

    // Reserva memoria
    arreglo_puntero = malloc(sizeof(int) * 5);

    // Asignación de valores
    pos = arreglo_puntero;
    *pos = 10;
    pos++;
    *pos = 20;
    pos++;
    *pos = 30;
    pos++;

    // Declaración como String
    char cadena[] = "hola";

    // Declarración como arreglo de char
    char otra_cadena[] = {'M', 'u', 'n', 'd', 'o', '\0'};

    // Invocación a funciones y pasaje de parametros
    print_contenido_1(arreglo_enteros, 3);
    print_contenido_1(arreglo_puntero, 3);
    print_contenido_2(arreglo_ejemplo, 6);
    print_contenido_2(arreglo_puntero, 3);
    print_cadena_1(cadena);
    print_cadena_2(otra_cadena);

    */
}
