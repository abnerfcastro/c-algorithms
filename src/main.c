#include "../include/sorting.h"
#include "../include/arraylist.h"
#include "../include/linkedlist.h"
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

// string print_node(array_node node)
// {
//     string str = malloc(100 * sizeof(char));
//     sprintf(str, "{ Name: %s | Age: %d }", node.name, node.age);
//     return str;
// }

void test_linked_lists();
void test_linked_lists_2();

int main(int argc, char const *argv[]) {

    // test_linked_lists();
    test_linked_lists_2();

    // int x;
    // while (scanf("%d", &x) != EOF)
    //     printf("%d\n", x);

    // int array[ARRAY_SIZE] = {5, 4, 3, 2, 1};
    // print_array(array, (size_t)ARRAY_SIZE);
    // bubble_sort(array, (size_t)ARRAY_SIZE);
    // print_array(array, (size_t)ARRAY_SIZE);

    // array_list list = create_arraylist(0);    

    // array_node node;
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

    // node.name = "Abner";
    // node.age = 24;
    // add_node(list, node, HEAD);

    // node.name = "Deborah";
    // node.age = 23;
    // add_node(list, node, HEAD);

    // node.name = "Alex";
    // node.age = 13;
    // add_node(list, node, HEAD);

    // node.name = "Jack";
    // node.age = 30;
    // add_node(list, node, HEAD);

    

    // print_arraylist(list, "\n", print_node);

    // printf("\n\n");

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

typedef struct point
{
    int x;
    int y;
} point;

string print_ll_node(list_node node)
{
    void *data = node.data;
    point *p = (point *)data;
    string str = malloc(100 * sizeof(char));
    sprintf(str, "(%d, %d)", p->x, p->y);
    return str;
}

void test_linked_lists()
{
    linked_list list;
    ll_create_list(&list);    

    for (int i = 0; i < 10; i++)
    {
        printf("Writing data. Size: %d\n", list->size);
        point *p = malloc(sizeof(point));
        p->x = 2 * i;
        p->y = 3 * i;
        printf("Size of list: %d\n", sizeof(list));
        list_node node;
        node.data = p;
        ll_add_node(&list, node, TAIL);
    }

    print_linkedlist(list, "\n", print_ll_node);
    printf("\n\n");
    
    point p1;
    p1.x = 100000;
    p1.y = 150000;

    // point p2;
    // p2.x = 20;
    // p2.y = 40;
    
    list_node node;    
    
    node.data = &p1;
    ll_add_node(&list, node, 5);
    // ll_add_node(&list, node, 20);

    ll_remove_node(&list, 1);

    print_linkedlist(list, "\n", print_ll_node);

    for (int i = 0; i < 10; i++)
    {
        ll_remove_node(&list, HEAD);
    }

    ll_remove_node(&list, HEAD);

    print_linkedlist(list, "\n", print_ll_node);

    // node.data = &p2;
    // ll_add_node(list, node);
    // ll_add_node(list, node);
    // ll_add_node(list, node);
    // ll_add_node(list, node);

    // list_node tmp = ll_get_node(list, 2);
    // list_node tmp = *(list->head);

    // void *data = tmp.data;    
    // point *p_tmp = (point *)data;
    // printf("%d %d\n", p_tmp->x, p_tmp->y);
    printf("Size: %d\n", list->size);

}

void test_linked_lists_2()
{
    typedef struct person {
        string name;
        int age;
    } Person;

    string print_ll_node_person(list_node node)
    {
        void *data = node.data;
        Person *p = (Person *)data;
        string str = malloc(100 * sizeof(char));
        sprintf(str, "{Name: %s, Age: %d}", p->name, p->age);
        return str;
    }

    linked_list list;
    ll_create_list(&list);

    string pname = malloc(20 * sizeof(char));
    int page;
    while (scanf("%s %d", pname, &page) != EOF)
    {
        Person *p = malloc(sizeof(Person));
        p->name = pname;
        p->age = page;
        list_node node;
        node.data = p;
        ll_add_node(&list, node, HEAD);
        pname = malloc(20 * sizeof(char));
    }

    Person abner;
    abner.name = "Abner";
    abner.age = 24;

    Person deb;
    deb.name = "Deborah";
    deb.age = 23;

    list_node node_abner, node_deb;
    node_abner.data = &abner;
    node_deb.data = &deb;

    ll_add_node(&list, node_abner, HEAD);
    ll_add_node(&list, node_deb, HEAD);

    print_linkedlist(list, "\n", print_ll_node_person);

    ll_remove_node(&list, 10);

    printf("\n");

    print_linkedlist(list, "\n", print_ll_node_person);

}