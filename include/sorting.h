#ifndef _SORTING_H
#define _SORTING_H

typedef char bool;
#define true 1
#define false 0

typedef unsigned int size_t;

extern void print_array(int array[], size_t size);
extern void bubble_sort(int array[], size_t size);
extern void swap(int *a, int *b);

#endif
