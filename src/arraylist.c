/**********************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Implementation file for Array List data structure
 **********************************************************/

#include "../include/arraylist.h"

#define ERROR_CODE 0xf0000000
#define SUCCESS_CODE 0x0000000
#define MEM_ALLOC_ATTEMPTS 10

int realloc_array(array_list list);
void insert_at_head(array_list list, array_node node);
void insert_at_tail(array_list list, array_node node);
void insert_anywhere(array_list list, array_node node, int position);
void move_array_up(array_list list, int position);
void move_array_down(array_list list, int position);

array_list create_arraylist(size_t size)
{
    array_list list = malloc(sizeof(array_list));
    list->array = malloc(size * sizeof(array_node));
    list->size = 0;
    list->allocated_size = size;
    return list;
}

void destroy_arraylist(array_list list)
{
    free(list->array);
    free(list);
}

int realloc_array(array_list list)
{
    int attempts = MEM_ALLOC_ATTEMPTS;
    size_t new_size = (list->allocated_size != 0) ? list->allocated_size * 2 : 1;
    array_node *tmp;

    while (attempts)
    {        
        tmp = malloc(new_size * sizeof(array_node));
        if (tmp)
            break;
        else
            attempts--;        
    }
    
    if (tmp)
    {        
        // tmp has been allocated successfully, now copy all data to it
        memcpy(tmp, list->array, list->size * sizeof(array_node));
        list->array = tmp;
        list->allocated_size = new_size;
        return SUCCESS_CODE;
    }
    else
    {
        // There has been a problem with malloc
        return ERROR_CODE;
    }
}

void add_node(array_list list, array_node node, int position)
{
    // Check if more memory is needed
    if (list->size >= list->allocated_size)
    {
        // Allocates more memory to the list
        int return_value = realloc_array(list);
        if (return_value == ERROR_CODE)
        {
            // Error upon allocating more memory.
            return;
        }
    }

    // Fix position to avoid errors or out of bounds
    if (position < HEAD)
    {
        position = HEAD;
    }
    else if (position >= list->size)
    {
        position = TAIL;
    }

    switch (position)
    {
       case HEAD:
           insert_at_head(list, node);
           break;
       case TAIL:
           insert_at_tail(list, node);
           break;
       default:
           insert_anywhere(list, node, position);
           break;
    }
}

void insert_at_head(array_list list, array_node node)
{
    move_array_up(list, 0);
    list->array[0] = node;
    list->size++;
}

void insert_at_tail(array_list list, array_node node)
{
    int position = list->size;
    list->array[position] = node;
    list->size++;
}

void insert_anywhere(array_list list, array_node node, int position)
{    
    list->array[position] = node;
    list->size++;
}

void move_array_up(array_list list, int position)
{    
    for (size_t i = list->size; i > position; i--) {
        list->array[i] = list->array[i - 1];
    }
}

void remove_node(array_list list, int position)
{
    // Fix position to avoid errors or out of bounds
    if (position < HEAD)
    {
        position = HEAD;
    }
    else if (position >= list->size)
    {
        position = TAIL;
    }

    switch (position)
    {
       case HEAD:
           move_array_down(list, HEAD);
           break;
       case TAIL:
           move_array_down(list, TAIL);
           break;
       default:
           move_array_down(list, position);
           break;
    }

    // Resize the list
    list->size--;
}

void move_array_down(array_list list, int position)
{
    printf("Moving down!\n");
    for (size_t i = position; i < list->size; i++) {
        list->array[i] = list->array[i + 1];
    }
}

array_node get_node(array_list list, int index)
{
    if (index >= 0 && index < list->size)
    {
        return list->array[index];
    }
    else
    {
        array_node error_node;
        error_node.data = ERROR_CODE;
        return error_node;
    }
}

size_t get_size(array_list list)
{
    return list->size;
}
