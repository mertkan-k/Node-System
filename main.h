#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARRAY_SIZE( array ) ( sizeof( array ) / sizeof( array[0] ) )

extern int myArray[5];

int doForAllInArray(int array[], void (*function)(int*), ...);
void printValue(int *value);
void changeValue(int *value);


#endif