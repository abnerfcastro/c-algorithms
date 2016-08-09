
#include "../include/linkedlist.h"

linked_list create_linkedlist()
{
    printf("Creating linked list.\n");
    linked_list list = malloc(sizeof(linked_list));
    list->head = NULL;
    list->size = 0;
    return list;
}

void ll_add_node(linked_list list, list_node node, int position)
{
    // Allocate memory for new node
    list_node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
        return;
    
    new_node->data = node.data;

    // If list is empty
    if (list->head == NULL)
    {        
        list->head = new_node;
        list->head->next = NULL;
    }
    else
    {
        list_node *conductor = list->head;        
        
        // Insert at head of the list
        if (position <= 0)
        {
            list_node *tmp = conductor;
            conductor = new_node;
            conductor->next = tmp;
            list->head = conductor;
        }
        else
        {
            int counter = 0;
            while ((conductor->next != NULL))
            {
                if (counter == position - 1)
                    break;
                
                conductor = conductor->next;
                counter++;
            }

            list_node *tmp = conductor->next;
            conductor->next = new_node;
            new_node->next = tmp;
        }                
    }

    list->size++;
}

list_node ll_get_node(linked_list list, int position)
{    
    list_node *tmp = list->head;
    int index = 0;
    while (tmp && (index != position))
    {        
        tmp = tmp->next;
        index++;        
    }

    return *tmp;
}

void print_linkedlist(linked_list list, string separator, string (*to_string_function)(list_node node))
{
    for (int i = 0; i < list->size; i++)
    {
        list_node node = ll_get_node(list, i);
        printf("%s%s", to_string_function(node), separator);
    }
}