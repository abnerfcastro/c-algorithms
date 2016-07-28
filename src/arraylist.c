/**********************************************************
 * Author: Abner Castro
 * Date: July 26th, 2016
 * Description:
 *      Implementation file for Array List data structure
 **********************************************************/

 #include "../include/arraylist.h"

 #define ERROR_CODE 0xf0000000;

 void insert_at_head(array_list list, array_node node);
 void insert_at_tail(array_list list, array_node node);
 void insert_anywhere(array_list list, array_node node, int position);

 array_list create_arraylist(size_t size)
 {
     array_list list = malloc(sizeof(array_list));
     list->array = malloc(size * sizeof(array_node));
     list->size = 0;
     list->allocated_size = size;
     return list;
 }

 void add_node(array_list list, array_node node, int position)
 {
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
     printf("%s\n", "Insert at head. To be implemented.");
 }

 void insert_at_tail(array_list list, array_node node)
 {
     if (list->size == list->allocated_size)
     {
         // Allocate more space
     }
     else if (list->size < list->allocated_size)
     {
         int position = list->size;
         list->size++;
         list->array[position] = node;
     }
 }

 void insert_anywhere(array_list list, array_node node, int position)
 {
     printf("%s\n", "Insert anywhere. To be implemented.");
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
