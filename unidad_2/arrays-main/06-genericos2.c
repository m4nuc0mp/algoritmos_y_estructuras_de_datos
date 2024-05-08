#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "array_void.h"

typedef struct{
    int id;
    char* nombre;
} elem;


int cmp_elem_id (void* a, void* b){
    elem* aa = (elem*) a;
    elem* bb = (elem*) b;
    return aa->id - bb->id;
}

int cmp_elem_nombre (void* a, void* b){
    elem* aa = (elem*) a;
    elem* bb = (elem*) b;
    return strcmp(aa->nombre, bb->nombre);
}

void prt_elem(void* value){
    elem* e = (elem*) value;
    printf("(%02d,%s)", e->id, e->nombre);
}

void main (){
    printf("\n\n\norderna strunct:\n");

    char* nombres[] = {"juan", "maría", "fernando"};
    int ids[] = {2, 1, 3};
    void* a[255];
    int n = 3;
    
    for (int i = 0; i < n; i++){
        elem* e = malloc(sizeof(int));
        e->id = ids[i];        
        e->nombre = nombres[i];
        a[i] = e;
    }

    array_print(a, n, prt_elem);
    bubble_sort_func(a, n, cmp_elem_id);
    array_print(a, n, prt_elem);
    bubble_sort_func(a, n, cmp_elem_nombre);
    array_print(a, n, prt_elem);
    

}



