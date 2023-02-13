#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Stack Data Structure
typedef struct Stack
{
	int				*array;
	unsigned int	capacity;
	unsigned int	top;
} Stack;

// Functions
int my_atoi(char *number);
void print_error();

#endif