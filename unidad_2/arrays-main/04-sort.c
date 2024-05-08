#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_sort.h"
#include "array_basic.h"

void main() {
    printf("\n\n\n\n");
    int a[] = {1, 2, 5, 8, 12, 24, 21};
    int n = (int)sizeof(a) / sizeof(int);
   
    array_print(a, n);
    //select_sort(a, n);
    //bubble_sort_v1(a, n);
    bubble_sort_v2(a, n);
    array_print(a, n);
    
}