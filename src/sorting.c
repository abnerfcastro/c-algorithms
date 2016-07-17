#include <stdio.h>
#include "../include/sorting.h"

void print_array(int array[], size_t size)
{
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int array[], size_t size)
{
    int k = size - 1;
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < k; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
        k--;
    }
}

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
