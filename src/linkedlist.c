
#include "../include/linkedlist.h"

bool is_empty(linked_list list);
void ll_insert_at_head(linked_list list, list_node *new_node);
void ll_insert_at_tail(linked_list list, list_node *new_node);
void ll_insert_anywhere(linked_list list, list_node *new_node, int position);

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
    if (is_null(new_node))
        return;
    
    new_node->data = node.data;

    // If list is empty
    if (is_empty(list))
    {        
        new_node->next = NULL;
        list->head = new_node;        
    }
    else
    {
        // list_node *conductor = list->head;        
        
        // Insert at head of the list
        if (position <= 0)
        {
            ll_insert_at_head(list, new_node);            
        }
        else
        {
            if (position >= list->size)
            {
                ll_insert_at_tail(list, new_node);
            }
            else
            {
                // Insert anywhere
                ll_insert_anywhere(list, new_node, position);
            }                
            
            // int counter = 0;
            // while ((conductor->next != NULL))
            // {
            //     if (counter == position - 1)
            //         break;
                
            //     conductor = conductor->next;
            //     counter++;
            // }

            // list_node *tmp = conductor->next;
            // conductor->next = new_node;
            // new_node->next = tmp;
        }                
    }

    list->size++;
}

bool is_empty(linked_list list)
{
    return (list->head == NULL);
}

void ll_insert_at_head(linked_list list, list_node *new_node)
{
    list_node *tmp = list->head;
    new_node->next = tmp;
    list->head = new_node;
}

void ll_insert_at_tail(linked_list list, list_node *new_node)
{

}

void ll_insert_anywhere(linked_list list, list_node *new_node, int position)
{

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