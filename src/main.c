#include "../include/sorting.h"
#include "../include/arraylist.h"

#define ARRAY_SIZE 5

int main(int argc, char const *argv[]) {

    // int array[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    // print_array(array, (size_t)ARRAY_SIZE);
    // bubble_sort(array, (size_t)ARRAY_SIZE);
    // print_array(array, (size_t)ARRAY_SIZE);

    array_list list = create_arraylist(10);
    printf("%d\n", get_size(list));

    array_node node;

    node.data = 5;
    add_node(list, node, TAIL);
    printf("%d\n", get_size(list));

    node.data = 6;
    add_node(list, node, TAIL);
    printf("%d\n", get_size(list));

    node.data = 10;
    add_node(list, node, TAIL);
    printf("%d\n", get_size(list));

    printf("Node at 0: %d\n", get_node(list, 0));
    printf("Node at 1: %d\n", get_node(list, 1));
    printf("Node at 2: %d\n", get_node(list, 2));
    printf("Node at 3: %d\n", get_node(list, 3));


    return 0;
}
