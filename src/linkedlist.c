/****************************************************
 * Author: Abner Castro
 * Date: August 16th, 2016
 * Description:
 *      Implementation file for Linked List data structure
 ****************************************************/

#include "../include/linkedlist.h"

void ll_insert_at_head(linked_list *list, list_node *new_node);
void ll_insert_at_tail(linked_list *list, list_node *new_node);
void ll_insert_anywhere(linked_list *list, list_node *new_node, int position);
void ll_remove_head(linked_list *list);
void ll_remove_tail(linked_list *list);
void ll_remove_anywhere(linked_list *list, int position);
list_node* ll_get_node_reference(linked_list list, int position);

bool ll_create_list(linked_list *list)
{
    // Allocates memory for a new linked_list
    *list = malloc(sizeof(linked_list *));
    
    if (is_null(*list))
        return false;
    
    // Initiates list properties
    (*list)->size = 0;
    (*list)->head = malloc(sizeof(list_node));
    (*list)->tail = malloc(sizeof(list_node));

    return true;
}

bool ll_add_node(linked_list *list, list_node node, int position)
{
    // Allocate memory for new node
    list_node *new_node = malloc(sizeof(node));
    if (is_null(new_node))
        return false;
    
    new_node->data = node.data;

    // If list is empty, insert first node
    if (ll_is_empty(*list))
    {        
        new_node->next = NULL;
        (*list)->head = new_node;
        (*list)->tail = new_node;
    }
    else
    {
        // Insert at head of the list
        if (position <= 0)
        {
            ll_insert_at_head(list, new_node);
        }
        else
        {
            if (position >= (*list)->size)
            {
                // Insert at tail
                ll_insert_at_tail(list, new_node);
            }
            else
            {
                // Insert anywhere
                ll_insert_anywhere(list, new_node, position);
            }                
        }                
    }

    (*list)->size++;
    return true;
}

bool ll_is_empty(linked_list list) {
    return (list->size == 0);
}

void ll_insert_at_head(linked_list *list, list_node *new_node)
{
    list_node *tmp = (*list)->head;
    new_node->next = tmp;
    (*list)->head = new_node;
}

void ll_insert_at_tail(linked_list *list, list_node *new_node)
{    
    list_node *tmp = (*list)->tail;
    tmp->next = new_node;
    new_node->next = NULL;
    (*list)->tail = new_node;
}

void ll_insert_anywhere(linked_list *list, list_node *new_node, int position)
{
    list_node *tmp = ll_get_node_reference(*list, position - 1);
    new_node->next = tmp->next;
    tmp->next = new_node;
}

bool ll_remove_node(linked_list *list, int position)
{
    if (ll_is_empty(*list) || position < 0)
        return false;

    // In case position is out of bounds
    if (position >= (*list)->size)
        position = TAIL;    

    switch (position)
    {
        case HEAD:
            ll_remove_head(list);
            break;
        case TAIL:
            ll_remove_tail(list);
            break;
        default:
            ll_remove_anywhere(list, position);
            break;
    }

    (*list)->size--;
    return true;
}

void ll_remove_head(linked_list *list)
{
    list_node *tmp = (*list)->head;
    (*list)->head = tmp->next;
    free(tmp);
}

void ll_remove_tail(linked_list *list)
{
    list_node *before_tail = ll_get_node_reference(*list, (*list)->size - 2);
    before_tail->next = NULL;
    list_node *tmp = (*list)->tail;
    (*list)->tail = before_tail;
    free(tmp);
}

void ll_remove_anywhere(linked_list *list, int position)
{
    list_node *tmp = ll_get_node_reference(*list, position - 1);
    list_node *to_be_removed = tmp->next;
    tmp->next = to_be_removed->next;
    free(to_be_removed);
}


list_node* ll_get_node_reference(linked_list list, int position)
{
    list_node *tmp = list->head;
    int index = 0;
    while (tmp && (index != position))
    {        
        tmp = tmp->next;
        index++;        
    }

    return tmp;
}

list_node ll_get_node(linked_list list, int position)
{
    list_node *tmp = ll_get_node_reference(list, position);
    return *(tmp);
}

size_t ll_get_size(linked_list list)
{
    return list->size;
}

void print_linkedlist(linked_list list, string separator, string (*to_string_function)(list_node node))
{
    if (ll_is_empty(list))
        printf("The list is empty.\n");

    for (int i = 0; i < list->size; i++)
    {
        list_node node = ll_get_node(list, i);
        printf("%s%s", to_string_function(node), separator);
    }
}