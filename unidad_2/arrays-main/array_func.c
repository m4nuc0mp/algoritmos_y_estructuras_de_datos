#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_func.h"

int binary_sorted_search_func(int key, int a[], int n, int cmp (int, int)) {
    int high = n - 1;
    int low = 0;
    int i = (high - low) / 2;
    while ((low < high) && (cmp(a[i],key) != 0)) {
        if (cmp(key,a[i]) < 0) { // key < a[i] ? 
            high = i - 1;
        } else {
            low = i + 1;
        }
        i = low + (high - low) / 2;
    }
    return (a[i] == key) ? i : n;
}

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubble_sort_func(int a[], int n, int cmp (int, int) ) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (cmp(a[i - 1],a[i]) > 0) { // a[i - 1] > a[i] ?
                swap(&a[i - 1], &a[i]);
                swapped = 1;
            }
            printf(".");
        }
        n--;
    }
    printf("\n");
}


int compare (int a, int b) {
    return a - b;
}

int compare_inv (int a, int b) {
    return b - a;
}


void array_print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %02d ", a[i]);
    }
    printf("\n");
}





