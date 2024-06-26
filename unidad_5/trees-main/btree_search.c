#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**************************************************************/
/*                       NOMENCLATURAS                        */
/**************************************************************/
/**
 * BT - Binary Tree: Árbol binario.
 * BTN - binary tree node: nodo de árbol binario.
 * SBT - Search Binary Tree: ABB - Árbol binario de búsqueda.
 * AVL - AVL Tree: Árbol AVL.
 * root: nodo raíz del árbol.
 * parent node: nodo padre.
 * child node: nodo hijo.
 * internal node,
 * inner node,
 * inode,
 * branch node: nodo interno, que tiene hijos.
 * external node,
 * leaf node,
 * outer node,
 * terminal node: nodo hoja de un árbol.
 */
/**************************************************************/

#include "btree_base.c"

/**************************************************************/
/*             ÁRBOLES BINARIOS DE BÚSQUEDA                   */
/**************************************************************/

/**
 * Devuelve el valor máximo entre 2 enteros.
 * Función auxiliar utilizada en height.
 */
t_elem_btree _max_elem (t_elem_btree a, t_elem_btree b, int cmp (t_elem_btree, t_elem_btree) ) {
    return (cmp(a, b) > 0) ? a : b;    
}

/**
 * Agrega un nodo a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          *newNode: puntero al nodo que se va a insertar en el SBT
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */
int sbt_insertnodo(btn **node, btn *newNode, int cmp (t_elem_btree, t_elem_btree)) {
    if (node == NULL) return 0;
    if (newNode == NULL) return 1;

    /**** COMPLETAR ****/
}

/**
 * Agrega un valor a un árbol binario de búsqueda (SBT)
 * (no agrega valores repetidos)
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a insertar
 *          value: el valor a agregar.
 * Devuelve:
 *  1 si pudo insertar
 *  0 si no pudo insertar
 */
int sbt_insert_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor mínimo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** sbt_get_minnodo(btn **node) {
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return node;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor mínimo de un SBT
 */
t_elem_btree sbt_min(btn *node) {
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor máximo de un
 * SBT.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar
 */
btn** sbt_get_maxnodo(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve el valor máximo de un SBT
 */
t_elem_btree sbt_get_max_value(btn *node) {
    if (node == NULL) return -1;
    btn **r = sbt_get_maxnodo(&node);
    return (*r)->value;
}


/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión recursiva)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn* sbt_findr(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa)
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          *node: el puntero al nodo del sub-árbol donde se
 * va a buscar.
 */
btn *sbt_findi(btn *node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}


/**
 * Obtiene el puntero que contiene el puntero al nodo con el valor solicitado de
 * un SBT.
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a buscar.
 */
btn** sbt_findnodo(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    if (node == NULL) return NULL;     // []->[]->nodo
    if ((*node) == NULL) return NULL;  // []->nodo

    /**** COMPLETAR ****/
}

/**
 * Obtiene el puntero al nodo con el valor solicitado de
 * un SBT. (Versión iterativa en reducida) * 
 * Parámetros:
 *          value: el valor que se busca en el SBT.
 *          **node: referencia al puntero al nodo del sub-árbol donde se
 * va a buscar.
 * Devuelve una doble puntero para permitir la modificación.
 */
btn** sbt_findii(btn** node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Devuelve 1 si un valor se encuentra en el árbol, o 0 si no se encuentra
 */
int sbt_in(btn* node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por su rama Derecha y agregando
 * la rama Izquierda a la rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* sbt_removenodo(btn **node,  int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por el máximo de su rama
 * izquierda, o en su defecto por el mínimo de su rama derecha.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn* sbt_removenodo2(btn **node) {
    /**** COMPLETAR ****/
}

/**
 * Quita un nodo de un SBT, reemplazando el nodo por
 * 1) el máximo de su rama izquierda, si la rama izquierda es igual o más alta
 * que la derecha.
 * 2) el mínimo de su rama derecha, si la rama derecha es más
 * alta que la izquierda.
 * Parámetros:
 *          **node: debe ser la dirección de memoria (en la estructura del padre
 * o la raíz) que donde se encuentra el puntero al nodo del subárbol donde se
 * va a eliminar.
 */
btn *sbt_removenodo_smart(btn **node) {
    if (!node) return NULL;
    if (!(*node)) return NULL;

    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo por el hijo derecho.
 * Devuelve 1 si pudo eliminarlo,
 * Devuelve 0 si no pudo
 */
int sbt_remove_value(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * derecha. Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int sbt_remove_value2(btn **node, t_elem_btree value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}

/**
 * Elimina un valor de un SBT.
 * Usa método de reemplazo del máximo de la rama izquierda o mínimo de la rama
 * según cual sea más alto.
 * Devuelve 1 si pudo eliminarlo, o 0 si no pudo.
 */
int sbt_remove_value_smart(btn **node, int value, int cmp (t_elem_btree, t_elem_btree)) {
    /**** COMPLETAR ****/
}