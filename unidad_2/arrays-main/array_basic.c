#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_basic.h"

void array_print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %02d ", a[i]);
    }
    printf("\n");
}

void array_add_last(int a[], int* n, int value) {
    a[*n] = value;
    (*n)++;
}

void array_add_sort(int a[], int* n, int value) {
    int i = 0;
    while ((i < *n) && (a[i] < value)) {
        i++;
    }

    for (int j = *n; j > i; j--) {
        a[j] = a[j - 1];
    }

    a[i] = value;
    (*n)++;
}

void array_del(int a[], int* n, int index) {
    (*n)--;
    for (int i = index; i < (*n); i++) {
        a[i] = a[i + 1];
    }
}

int* array_create(int n) {
    int* result;
    result = malloc(sizeof(int) * n);
    return result;
}

int* array_clone(int a[], int n) {
    int* result = array_create(n);
    for (int i = 0; i < n; i++) {
        result[i] = a[i];
    }
    return result;
}

