/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:33:45 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/26 19:02:09 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
#define STACK_H

// Libraries
#include <stdio.h>

// Stuctures
typedef struct Stack {
    int data;
    size_t index;
    struct Stack *prev;
    struct Stack *next;
} Stack;

typedef struct StackInterface
{
	size_t top;
    Stack *first;
    Stack *last;
    char name;
} StackInterface;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Functions <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// Print commands function
void print_command(char first, char sec);
void print_command_adn(char first, char sec, char additional);

// TODO: delete
void print_stack(StackInterface *stack, int all, char stack_name); // TODO: delete

StackInterface *init_stack(char name);
void create_stack(int *list, size_t size, StackInterface *istack);
void index_stack(Stack *stack, size_t size);
void sort_list(int *stack, size_t size);
void indexing_stack(Stack *stack, int *temp, size_t size);

// Operations
void swap(StackInterface *stack, short idf);
void swap_together(StackInterface *stack_a, StackInterface *stack_b);
void push_stack(StackInterface **fromStack, StackInterface *toStack);
void rotate(StackInterface *stack, short idf);
void rotate_together(StackInterface *s1, StackInterface *s2);
void reverse(StackInterface *stack, short idf);
void reverse_together(StackInterface *s1, StackInterface *s2);
void make_stack_empty(StackInterface *stack);
void pop(StackInterface *istack, Stack **p_stack);
void push(StackInterface *istack, Stack *stack);

// If All is ok then start sort :)
void select_algorithm(StackInterface *stack_a, StackInterface *stack_b);
void sort_3(StackInterface *stack_a);
short check_if_sorted(StackInterface *stack);
short check_ssort(StackInterface *stack);
void butterfly(StackInterface *stack_a, StackInterface *stack_b);
void butterfly_reverse(StackInterface *stack_a, StackInterface *stack_b);

// Get N
size_t    get_n(size_t i);
size_t    ft_ln(size_t nb);
size_t    ft_sqrt(size_t nb);
#endif










