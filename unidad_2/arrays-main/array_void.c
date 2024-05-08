#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_void.h"

void swap (void **a, void **b){
    void* aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort_func(void* a[], int n, int cmp (void*, void*) ) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(a[i - 1],a[i]) > 0) { // a[i - 1] > a[i] ?
                swap(&a[i-1], &a[i]);
                swapped = 1;
            }
        }
        n--;
    }
}

void array_print(void* a[], int n, void prt (void*)) {
    for (int i = 0; i < n; i++) {
        prt(a[i]);
        printf (" ");
    }
    printf("\n");
}

