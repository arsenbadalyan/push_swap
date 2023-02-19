/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:25:28 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/19 20:16:32 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack	*create_stack(int *list, int size, StackInterface *istack)
{
	Stack	*stack;
	int		i;

	i = -1;
	stack = (Stack *)malloc(sizeof(*stack) * size);
	while (++i < size)
	{
		stack[i].index = i;
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
	
	return (stack);
}

// void index_stack(Stack *stack, i)
// {
	
// }















