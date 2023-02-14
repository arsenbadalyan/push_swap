#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// Libraries
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// Stack Data Structure
typedef struct Stack {
    int data;
    struct Stack *prev;
    struct Stack *next; 
} Stack;

typedef struct StackInterface
{
	size_t top;
    Stack *first;
    Stack *last;
} StackInterface;

// Functions
int my_atoi(char *number, char **splited);
void print_error();
void free_me(void *addr, char **addr_2D);
char **ft_split(const char *s, char c);
int *mkarr_check_doubles(char **argv, int argc, int size);
char **splited_arr(char *str, char seperator);

#endif