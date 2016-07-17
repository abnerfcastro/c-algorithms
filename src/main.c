#include "../include/sorting.h"

#define ARRAY_SIZE 5

int main(int argc, char const *argv[]) {
    int array[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    print_array(array, (size_t)ARRAY_SIZE);
    bubble_sort(array, (size_t)ARRAY_SIZE);
    print_array(array, (size_t)ARRAY_SIZE);

    return 0;
}
