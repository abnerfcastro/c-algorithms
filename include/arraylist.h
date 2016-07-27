/****************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Include file for Array List data structure
 ****************************************************/

#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>     // malloc

#define HEAD        0x01
#define ANYWHERE    0x02
#define TAIL        0x03

// Structure to hold the information
typedef struct arraylist_node
{
    int data;
} array_node;

typedef struct _array_list
{
    array_node *array;
    size_t size;
} _array_list;

typedef _array_list* array_list;

array_list create_arraylist(size_t size);
array_node get_node(array_list list, int index);
void add_node(array_list list, array_node node, int position);
void remove_node(array_list list, int position);
size_t get_size(array_list list);

#endif
