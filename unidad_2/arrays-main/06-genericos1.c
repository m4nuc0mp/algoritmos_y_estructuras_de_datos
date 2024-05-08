#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "array_void.h"

int cmp_int (void* a, void* b){
    int* aa = (int*) a;
    int* bb = (int*) b;
    return *aa - *bb;
}

void prt_int(void* value){
    int* v = (int*) value;
    printf("%02d", *v);
}

void main (){
    printf("\n\n\n\n\n\nOrdena enteros:\n");

    void* a[255];
    int n = 10;
    
    srand(time(NULL));    
    for (int i = 0; i < n; i++){
        int* r = malloc(sizeof(int));        
        *r = rand() % 100;        
        a[i] = r;
    }

    array_print(a, n, prt_int);
    bubble_sort_func(a, n, cmp_int);
    array_print(a, n, prt_int);

}

