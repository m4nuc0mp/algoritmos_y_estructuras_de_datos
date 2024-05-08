#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array_search.h"

int sequential_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] != key)) {
        i++;
    }    
    return (i >= n)? -1 : i;
}

int sequential_sorted_search(int key, int a[], int n) {
    int i = 0;
    while ((i < n) && (a[i] < key)) {
        i++;
    }
    return (a[i] == key) ? i : n;
}

int binary_sorted_search(int key, int a[], int n) {
    int high = n - 1;
    int low = 0;
    int mid = (high - low) / 2;
    while ((low < high) && (a[mid] != key)) {
        if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (high + low) / 2;
    }
    return (a[mid] == key) ? mid : n;
}


