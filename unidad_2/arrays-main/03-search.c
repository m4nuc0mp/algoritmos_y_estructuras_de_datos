#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_search.h"

void main() {
    printf("\n\n\n\n");
    int a[] = {1, 2, 5, 8, 12, 20, 21};
    int n = (int)sizeof(a) / sizeof(int);
    int where = 0;
    int what = 8;

    // where = sequential_search(what, a, n);
    // where = sequential_sorted_search(what, a, n);
    where = binary_sorted_search(what, a, n);
    
    if (where < n) {
        printf(" El valor %d, se encuentra en posición %d\n", what, where);
    } else {
        printf(" El valor %d, no se encuentra en el arreglo\n", what);
    }
}
