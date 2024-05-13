#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include "cabecera.h"
#define tipo_elemento lecturas

typedef struct _pila
{
    tipo_elemento valor;
    struct _pila* proximo;
} pila;

pila* crear_nodo_pila(int tam_max);
void liberar_pila_en_memoria(pila* p);
int obtener_tam_pila(pila* p);
int obtener_tam_max_pila(pila* p);
int decir_si_pila_vacia(pila* p);
int decir_si_pila_llena(pila* p);
void ingresar_en_pila(pila* p, tipo_elemento e);
tipo_elemento sacar_de_pila(pila* p);
tipo_elemento ver_tope_pila(pila* p);
void eliminar_pila(pila* p, void eliminar_elemento(tipo_elemento e));
pila* generar_pila_aleatoria_temps(int cantidad);

#endif // PILAS_H_INCLUDED