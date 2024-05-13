#include "pilas.h"

pila* crear_nodo_pila(tipo_elemento elemento)
{
    pila* nuevo_nodo = (pila*) malloc(sizeof(pila));

    if (NULL != nuevo_nodo)
    {
        nuevo_nodo->valor = elemento;
        nuevo_nodo->proximo = NULL;
    }
    return nuevo_nodo;
}

void liberar_pila_en_memoria(pila* p)
{
    pila* auxiliar = NULL;

    while (NULL != p)
    {
        auxiliar =   
    }
    
}

int obtener_tam_pila(pila* p)
{
    pila* auxiliar = NULL;
    int contador = 0;

    while (NULL != p)
    {
        auxiliar = sacar_de_pila(p);
        auxiliar->proximo = NULL;
        contador++;
    }

    while (NULL != auxiliar)
    {
        p = sacar_de_pila(auxiliar);
    }
    

    
}

int obtener_tam_max_pila(pila* p)
{

}

int decir_si_pila_vacia(pila* p)
{
    int vacia = 0;

    if (NULL == p)
    {
        vacia = 1;
    }
    return vacia;
}

int decir_si_pila_llena(pila* p)
{
    return 0;
}

void ingresar_en_pila(pila* p, tipo_elemento e)
{
    pila* nuevo_nodo = crear_nodo_pila(e);
    pila** cabecera = &p;

    /*
        h-->p
        nuevo-->p
        h-->nuevo
    */
   nuevo_nodo->proximo = p;

}

pila* sacar_de_pila(pila* p)
{
    pila* extraido = p;
    pila* p = p->proximo;

    return extraido;
}

tipo_elemento ver_tope_pila(pila* p)
{
    return p->valor;
}

void eliminar_pila(pila* p, void eliminar_elemento(tipo_elemento e))
{
    pila* eliminado = sacar_de_pila(p);
    eliminar_elemento(eliminado->valor);
    free(eliminado);
}
