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

 void add_node(array_list list, array_node node, int position)
 {
     // Check if more memory is needed
     if (list->size >= list->allocated_size)
     {
         // Allocates more memory to the list
         size_t new_size = (list->allocated_size != 0) ? list->allocated_size * 2 : 1;
         list->array = realloc(list->array, new_size * sizeof(array_node));
         list->allocated_size = new_size;
         printf("Allocating more space! New size = %d\n", list->allocated_size);
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
     move_array_up(list, position);
     list->array[position] = node;
     list->size++;
 }

 void move_array_up(array_list list, int position)
 {
     printf("Moving up!\n");
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
