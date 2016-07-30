#include "../include/sorting.h"
#include "../include/arraylist.h"

#define ARRAY_SIZE 5

int main(int argc, char const *argv[]) {

    // int array[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    // print_array(array, (size_t)ARRAY_SIZE);
    // bubble_sort(array, (size_t)ARRAY_SIZE);
    // print_array(array, (size_t)ARRAY_SIZE);

    array_list list = create_arraylist(0);
    printf("%d\n", get_size(list));

    array_node node;

    node.data = 5;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 6;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 10;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 20;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 15;
    add_node(list, node, TAIL);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 12;
    add_node(list, node, TAIL);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 13;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 9;
    add_node(list, node, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 17;
    add_node(list, node, 1);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 60;
    add_node(list, node, 2);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 100;
    add_node(list, node, -10);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 1000;
    add_node(list, node, 2000);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    node.data = 1230;
    add_node(list, node, 10);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    for (size_t i = 0; i < list->allocated_size; i++) {
        printf("Node at %d: %d\n", i, get_node(list, i));
    }

    remove_node(list, HEAD);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    remove_node(list, TAIL);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    remove_node(list, 5);
    printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    for (size_t i = 0; i < list->allocated_size; i++) {
        printf("Node at %d: %d\n", i, get_node(list, i));
    }

    destroy_arraylist(list);

    return 0;
}
