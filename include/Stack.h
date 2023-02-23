/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:33:45 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/19 21:06:28 by arsbadal         ###   ########.fr       */
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
} StackInterface;

// >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
// >>>>>>>>>> Functions <<<<<<<<<<
// <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

void print_stack(StackInterface *stack, int all, char stack_name); // TODO: delete

void create_stack(int *list, size_t size, StackInterface *istack);
void index_stack(Stack *stack, size_t size);
void sort_list(int *stack, size_t size);
void indexing_stack(Stack *stack, int *temp, size_t size);

// Operations
void swap_stack(StackInterface *stack);
void swap_together(StackInterface *stack_a, StackInterface *stack_b);
void push_stack(StackInterface **fromStack, StackInterface *toStack);

void make_stack_empty(StackInterface *stack);
void pop(StackInterface *istack, Stack **p_stack);
void push(StackInterface *istack, Stack *stack);

#endif










