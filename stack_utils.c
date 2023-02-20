/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:25:28 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/19 21:19:13 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void free_stack(StackInterface *stack)
{
	Stack *list;
	int i;

	i = 0;
	list = stack.first;
	if (!list)
		return;
	while (list[i].data != stack.first->data && i != 0)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

Stack *create_stack(int *list, int size, StackInterface *istack)
{
	Stack *stack;
	int i;

	i = -1;
	stack = (Stack *)malloc(sizeof(*stack) * size);
	while (++i < size && stack)
	{
		stack[i].index = 0;
		stack[i].data = list[i];
		if (i == 0)
			istack->first = (stack + i);
		else
		{
			stack[i].prev = (stack + i - 1);
			stack[i - 1].next = (stack + i);
		}
		if (i == size - 1)
		{
			istack->last = (stack + i);
			stack[0].prev = (stack + i);
			stack[i].next = stack;
		}
	}
	index_stack(stack, size);
	return (stack);
}

void index_stack(Stack *stack, int size)
{
	Stack *temp;
	int data;
	int i;

	i = 0;
	temp = (Stack *)malloc(sizeof(*temp) * size);
	if (!temp)
		stack = NULL;
	while (i < size)
	{
		temp[i] = stack[i];
		i++;
	}
	sort_list(temp, size);
	indexing_stack(stack, temp, size);
	i = 0;
	while (i < size)
	{
		printf("%lu - %d\n", stack[i].index, stack[i].data);
		i++;
	}
}

void sort_list(Stack *stack, int size)
{
	int i;
	int temp;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i].data > stack[i + 1].data)
		{
			temp = stack[i].data;
			stack[i].data = stack[i + 1].data;
			stack[i + 1].data = temp;
			i = 0;
			continue;
		}
		stack[i].index = i;
		i++;
	}
	stack[i].index = i;
}

void indexing_stack(Stack *stack, Stack *temp, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (temp[i].data == stack[j].data)
				stack[j].index = temp[i].index;
			j++;
		}
		i++;
	}
}