/****************************************************
 * Author: Abner Castro
 * Date: August 16th, 2016
 * Description:
 *      Include file for Linked List data structure
 ****************************************************/

#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/strings.h"

/**
 * Definition of list_node
 */
typedef struct ll_node
{
    void *data;
    struct ll_node *next;
} list_node;

/**
 * Definition of ll_struct
 */
typedef struct ll_struct
{
    size_t size;
    list_node *head;
    list_node *tail;
} ll_struct;

/**
 * Defines a pointer to ll_struct and names it linked_list
 */
typedef ll_struct* linked_list;

/**
 * Allocates memory for a new linked list and initiates its properties.
 *
 * @param *list points to the pointer that will be initialized.
 * @returns true if allocation was successful, false if not
 */
bool ll_create_list(linked_list *list);

/**
 * Adds node to the linked list.
 *
 * @param *list pointer to pointer of a list.
 * @param node the node to be added
 * @param position the position where the node will be added in the list.
 * @returns true if successful, false if not
 */
bool ll_add_node(linked_list *list, list_node node, int position);

/**
 * Removes node from the linked list.
 *
 * @param *list pointer to pointer of a list.
 * @param node the node to be added
 * @param position the position where the node will be added in the list.
 * @returns true if successful, false if list is empty or position < 0
 */
bool ll_remove_node(linked_list *list, int position);

/**
 * Returns node from the linked list.
 *
 * @param list the list to retrieve the node from
 * @param position the position where the node is in the list.
 * @returns the node
 */
list_node ll_get_node(linked_list list, int position);

/**
 * Checks if the list is empty.
 *
 * @param list the list to be checked
 * @returns true if empty, false otherwise
 */
bool ll_is_empty(linked_list list);

/**
 * Gets the size of the list
 *
 * @param list the list to be checked
 * @returns true if empty, false otherwise
 */
size_t ll_get_size(linked_list list);

/**
 * Prints a linked list.
 *      This function is customizable. Prints 'The list is empty' if so.
 *
 * @param list the list to be printed
 * @param separator the way to separate the nodes (e.g "\n", " - ", etc.)
 * @param to_string_function a function that defines how the list nodes are to be printed
 */
void print_linkedlist(linked_list list, string separator, string (*to_string_function)(list_node node));


#endif