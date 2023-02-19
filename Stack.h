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

Stack *create_stack(int *list, int size, StackInterface *istack);
void index_stack(Stack *stack, int size);

#endif










