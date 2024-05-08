#ifndef _ARRAY_BASIC
#define _ARRAY_BASIC

void array_print(int a[], int n);
void array_add_last(int a[], int* n, int value);
void array_add_sort(int a[], int* n, int value);
void array_del(int a[], int* n, int index);
int* array_create(int n);
int* array_clone(int a[], int n);

#endif