#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/strings.h"

typedef struct _ll_node
{
    void *data;
    struct _ll_node *next;
} list_node;

typedef struct _linked_list
{
    list_node *head;
    int size;

} _linked_list;

typedef _linked_list* linked_list;

linked_list create_linkedlist();

// Experimental function: only adds at tail
void ll_add_node(linked_list list, list_node node, int position);

list_node ll_get_node(linked_list list, int position);

void print_linkedlist(linked_list list, string separator, string (*to_string_function)(list_node node));


#endif