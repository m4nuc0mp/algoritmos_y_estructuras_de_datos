#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_sort.h"

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void select_sort(int a[], int n) {
    int aux = a[0];
    for (; n > 0; n--) {
        for (int i = 0; i < n; i++) {
            if (a[n - 1] < a[i]) {
                swap(&a[n - 1], &a[i]);
            }
            printf(".");
        }
    }
    printf("\n");
}

void bubble_sort_v1(int a[], int n) {
    for (; n > 0; n--) {
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
            }
            printf(".");
        }
    }
    printf("\n");
}

void bubble_sort_v2(int a[], int n) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                swap(&a[i - 1], &a[i]);
                swapped = 1;
            }
            printf(".");
        }
        n--;
    }
    printf("\n");
}

