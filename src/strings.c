/**********************************************************
 * Author: Abner Castro
 * Date: August 6th, 2016
 * Description:
 *      Implementation file for strings utils (strings.h)
 **********************************************************/

#include "../include/strings.h"

string parse_integer(int number)
{
    // Size 10 to be able to hold largest integer value possible
    string str = malloc(10 * sizeof(char));
    sprintf(str, "%d", number);
    return str;
}