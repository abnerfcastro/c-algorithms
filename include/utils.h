/****************************************************
 * Author: Abner Castro
 * Date: August 10th, 2016
 * Description:
 *      Include file for Utils
 ****************************************************/

#ifndef _UTILS_H
#define _UTILS_H

#include <stdio.h>

#define HEAD        0x00000000
#define TAIL        0x7fffffff

typedef enum { false, true } bool;

bool is_null(void *);

#endif