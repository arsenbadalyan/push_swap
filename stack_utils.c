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

Stack	*create_stack(int *list, int size, StackInterface *istack)
{
	Stack	*stack;
	int		i;

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
	if(!temp)
		stack = NULL;
	while(i < size)
	{
		temp[i] = stack[i];
		i++;
	}
	i = 0;
	while(i < size - 1)
	{
		if(temp[i].data > temp[i + 1].data)
		{
			data = temp[i].data;
			temp[i].data = temp[i + 1].data;
			temp[i + 1].data = data;
			i = 0;
			continue;
		}
		temp[i].index = i;
		i++;
	}
	temp[i].index = i;
	i = 0;
	while(i < size)
	{
		data = 0;
		while(data < size)
		{
			if(temp[i].data == stack[data].data)
				stack[data].index = temp[i].index;
			data++;
		}
		i++;
	}
	i = 0;
	while(i < size)
	{
		printf("data: %d - index: %lu\n", stack[i].data, stack[i].index);
		i++;
	}
	
}















