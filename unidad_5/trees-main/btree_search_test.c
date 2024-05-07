

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "btree_search.c"

// toStr devuelve el contenido de un nodo como string
// asume que t_elem_tree es un número entero
void btn_intToStr(btn* node, char* str) {
    if (!node) return;    
    sprintf(str, "(%03d)", node->value);    
}

// compara 2 elementos del árbol cuando son enteros
int btn_cmp_int(t_elem_btree a, t_elem_btree b) {
    return a - b;
}


void main(){
    btn* root = NULL;
    sbt_insert_value (&root, 20, btn_cmp_int);
    sbt_insert_value (&root, 10, btn_cmp_int);
    sbt_insert_value (&root, 15, btn_cmp_int);
    sbt_insert_value (&root, 12, btn_cmp_int);
    sbt_insert_value (&root, 30, btn_cmp_int);
    sbt_insert_value (&root, 25, btn_cmp_int);
    sbt_insert_value (&root, 35, btn_cmp_int);
    sbt_insert_value (&root, 40, btn_cmp_int);

    printf("\n%10s: \n", "Árbol");
    btn_print(root, btn_intToStr);

    sbt_remove_value (&root, 20, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin nel 20");
    btn_print(root, btn_intToStr);

    sbt_insert_value (&root, 28, btn_cmp_int);
    sbt_insert_value (&root, 29, btn_cmp_int);
    sbt_insert_value (&root, 27, btn_cmp_int);
    sbt_insert_value (&root, 32, btn_cmp_int);
    sbt_insert_value (&root, 33, btn_cmp_int);
    sbt_insert_value (&root, 9, btn_cmp_int);
    sbt_insert_value (&root, 20, btn_cmp_int);
    sbt_insert_value (&root, 31, btn_cmp_int);
    sbt_insert_value (&root, 36, btn_cmp_int);
    sbt_insert_value (&root, 45, btn_cmp_int);


    printf("\n%10s: \n", "Árbol con más nodos");
    btn_print(root, btn_intToStr);

    sbt_remove_value2 (&root, 25, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin el 25");
    btn_print(root, btn_intToStr);

    sbt_remove_value_smart (&root, 10, btn_cmp_int);

    printf("\n%10s: \n", "Árbol sin el 10");
    btn_print(root, btn_intToStr);
 
}
