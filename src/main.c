#include "../include/sorting.h"
#include "../include/arraylist.h"
#include "../include/strings.h"

#define ARRAY_SIZE 5

// string print_node(array_node node)
// {
//     return parse_integer(node.data);
// }

// string print_node_curly(array_node node)
// {
//     string str = malloc(10 * sizeof(char));
//     sprintf(str, "{ %s }", parse_integer(node.data));
//     return str;
// }

string print_node(array_node node)
{
    string str = malloc(100 * sizeof(char));
    sprintf(str, "{ Name: %s | Age: %d }", node.name, node.age);
    return str;
}

int main(int argc, char const *argv[]) {

    // int array[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    // print_array(array, (size_t)ARRAY_SIZE);
    // bubble_sort(array, (size_t)ARRAY_SIZE);
    // print_array(array, (size_t)ARRAY_SIZE);

    array_list list = create_arraylist(0);    

    array_node node;
    // node.data = 0;

    // for (int i = 0; i < 10000; i++)
    // {
    //     if (i % 2 == 0)
    //     {
    //         add_node(list, node, HEAD);
    //     }
    //     else
    //     {
    //         add_node(list, node, TAIL);
    //     }
    //     node.data++;
    // }

    node.name = "Abner";
    node.age = 24;
    add_node(list, node, HEAD);

    node.name = "Deborah";
    node.age = 23;
    add_node(list, node, HEAD);

    node.name = "Alex";
    node.age = 13;
    add_node(list, node, HEAD);

    node.name = "Jack";
    node.age = 30;
    add_node(list, node, HEAD);

    

    print_arraylist(list, "\n", print_node);

    printf("\n\n");

    // remove_node(list, HEAD);
    // printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    // remove_node(list, TAIL);
    // printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    // remove_node(list, 5);
    // printf("Size: %d :: Allocated Size: %d\n", get_size(list), list->allocated_size);

    // for (size_t i = 0; i < list->allocated_size; i++) {
    //     printf("Node at %d: %d\n", i, get_node(list, i));
    // }

    // node.data = 10;
    // for (int i = 0; i < 1000000; i++)
    // {
    //     add_node(list, node, TAIL);
    // }

    // printf("Size: %d :: Allocated Size: %d\n", list->size, list->allocated_size);

    // destroy_arraylist(list);

    return 0;
}
