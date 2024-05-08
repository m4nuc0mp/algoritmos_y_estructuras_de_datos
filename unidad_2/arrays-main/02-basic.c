#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_basic.h"


void main() {
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

    int a[255] = {1, 5, 2, 8, 9, 12, 23};
    int n = 7;
    int* b = array_clone(a, n);
    int m = n;
    
    array_print(a, n);
    array_add_sort(a, &n, 6);
    array_add_last(a, &n, 30);
    array_print(a, n);
    array_print(b, m);
    
}