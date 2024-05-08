#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_func.h"

void main(){
    printf("\n\n\n\n\n");

    int a[255] = {1, 5, 2, 8, 21, 12, 3};
    int n = 7;

    array_print(a, n);
    bubble_sort_func(a, n, compare);
    array_print(a, n);

    int where = 0;
    int what = 2;
    where = binary_sorted_search_func(what, a, n, compare);
    
    if (where < n) {
        printf(" El valor %d, se encuentra en posición %d\n", what, where);
    } else {
        printf(" El valor %d, no se encuentra en el arreglo\n", what);
    }

    bubble_sort_func(a, n, compare_inv);
    array_print(a, n);

    what = 2;
    where = binary_sorted_search_func(what, a, n, compare_inv);
    
    if (where < n) {
        printf(" El valor %d, se encuentra en posición %d\n", what, where);
    } else {
        printf(" El valor %d, no se encuentra en el arreglo\n", what);
    }
    
}
