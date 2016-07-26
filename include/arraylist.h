/****************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Include file for Array List data structure
 ****************************************************/

#ifndef _STRUCTURES_H
#define _STRUCTURES_H

#define HEAD        1
#define ANYWHERE    2
#define TAIL        3

// Structure to hold the information
typedef struct arraylist_node
{    
    int data;

} array_node;

typedef array_node[] array_list;

array_list create_arraylist(size_t size);
array_node get_node(array_list list, int index);
void add_node(array_list list, array_node node, int location, int position = 0);
void remove_node(array_list, int location, int position = 0);
size_t get_size(array_list list);

#endif