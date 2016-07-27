/**********************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Implementation file for Array List data structure
 **********************************************************/

 #include "../include/arraylist.h"

 array_list create_arraylist(size_t size)
 {
     array_list list = malloc(sizeof(array_list));
     list->array = malloc(size * sizeof(array_node));
     list->size = size;
     return list;
 }

 void add_node(array_list list, array_node node, int position)
 {
     // TODO needs huge improvement. This is just for testing.
     list->array[position] = node;
 }

 array_node get_node(array_list list, int index)
 {
     // TODO needs huge improvement. This is just for testing.
     return list->array[index];
 }

 size_t get_size(array_list list)
 {
     return list->size;
 }
