#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Libraries <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "Stack.h"

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Functions <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Utilites
void print_error();
void free_me(void *addr, char **addr_2D);
char **ft_split(const char *s, char c); // in one file
char **splited_arr(char *str, char seperator);

// Checking
int my_atoi(char *number, char **splited);
int *mkarr_check_doubles(char **argv, int argc, size_t size);
int check_doubles(int *num_list, size_t size);
size_t validate_arguments(int argc, char **argv);
char *check_zeros(char *number);


#endif