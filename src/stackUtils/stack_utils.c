/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:25:28 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/27 21:11:58 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_chain(t_stack *istack, t_list *current, t_list *prev, size_t size)
{
	if (!istack || !current)
		return ;
	if (istack->top == 0)
		istack->first = current;
	else
	{
		prev->next = current;
		current->prev = prev;
	}
	if (istack->top == size - 1)
	{
		istack->last = current;
		istack->first->prev = istack->last;
		current->next = istack->first;
	}
}

void	create_stack(int *list, size_t size, t_stack *istack)
{
	t_list	*stack;
	t_list	*temp;

	istack->top = 0;
	temp = NULL;
	while (istack->top < size)
	{
		stack = (t_list *)malloc(sizeof(*stack));
		if (!stack)
		{
			free(list);
			istack->has_error = 1;
			return ;
		}
		stack->data = list[istack->top];
		stack_chain(istack, stack, temp, size);
		temp = stack;
		istack->top++;
	}
	if (stack)
		index_stack(istack->first, size);
	free(list);
}

void	index_stack(t_list *stack, size_t size)
{
	int		*temp;
	size_t	i;

	i = 0;
	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		stack = NULL;
	while (i < size)
	{
		temp[i] = stack->data;
		stack = stack->next;
		i++;
	}
	sort_list(temp, size);
	indexing_stack(stack, temp, size);
	free(temp);
}

void	sort_list(int *stack, size_t size)
{
	size_t	i;
	int		temp;

	i = 0;
	while (i < size - 1)
	{
		if (stack[i] > stack[i + 1])
		{
			temp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = temp;
			i = 0;
			continue ;
		}
		i++;
	}
}

void	indexing_stack(t_list *stack, int *temp, size_t size)
{
	size_t	i;
	size_t	j;
	t_list	*head;

	i = 0;
	head = stack;
	while (i < size)
	{
		j = 0;
		stack = head;
		while (j < size)
		{
			if (temp[i] == stack->data)
				stack->index = i;
			stack = stack->next;
			j++;
		}
		i++;
	}
}
