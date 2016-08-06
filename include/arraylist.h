/****************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Include file for Array List data structure
 ****************************************************/

#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

#include <stdio.h>
#include <stdlib.h>     // malloc, realloc
#include <string.h>     // memcpy

#include "../include/strings.h"

#define HEAD        0x00000000
#define TAIL        0x7fffffff

// Node definition
typedef struct arraylist_node
{
    int data;
} array_node;

// Array List definition
typedef struct _array_list
{
    array_node *array;
    size_t size;
    size_t allocated_size;
} _array_list;

typedef _array_list* array_list;

/**
 * Creates an array list and allocates the necessary memory.
 *
 * @param size the initial size of the array list
 * @return reference to an array_list
 */
array_list create_arraylist(size_t size);

void destroy_arraylist(array_list list);

/**
 * Retrieves node from an array list.
 *      if index is less than zero, it will return node at position 0
 *      if index is out of bounds, it will return node at position size - 1 
 *
 * @param list the list to get the node from
 * @param index position of the node to be retrieved
 * @return copy of retrieved node
 */
array_node get_node(array_list list, int index);

/**
 * Adds a node to an array list.
 *      if position is negative, it will be set to HEAD
 *      if position is larger than the size of list, it will be set to TAIL
 *
 * @param list the list to add the node to
 * @param node the node to be added
 * @param position the position where the node will be added (can be HEAD, TAIL or other signed integer)
 */
void add_node(array_list list, array_node node, int position);

/**
 * Removes a node from an array list.
 *      if position is negative, it will be set to HEAD
 *      if position is larger than the size of list, it will be set to TAIL
 *
 * @param list the list to remove the node from
 * @param position the position where node to be removed is (can be HEAD, TAIL or other signed integer)
 */
void remove_node(array_list list, int position);

/**
 * Gets the size of the array list, that is, how many elements it holds.
 * 
 *
 * @param list the array list
 * @returns the size of the list
 */
size_t get_size(array_list list);

/**
 * Prints an array list.
 *      This function is customizable.
 *
 * @param list the list to be printed
 * @param separator the way to separate the nodes (e.g "\n", " - ", etc.)
 * @param to_string_function a function that defines how the array nodes are printed
 */
void print_arraylist(array_list list, string separator, string (*to_string_function)(array_node node));

#endif
