/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:05:28 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 22:06:17 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sel_alg(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return ;
	if (stack_a->top == 1)
		return ;
	if (stack_a->top == 2)
	{
		if (stack_a->first->data > stack_a->last->data)
			swap(stack_a, 1);
		return ;
	}
	if (stack_a->top == 3)
	{
		sort_3(stack_a);
		return ;
	}
	if (check_if_sorted(stack_a) || check_ssort(stack_a))
		return ;
	butterfly(stack_a, stack_b);
}

void	sort_3(t_stack *stack_a)
{
	t_list	*list;

	list = stack_a->first;
	if (list->index > list->next->index && list->index > list->prev->index)
		rotate(stack_a, 1);
	else if (list->next->index > list->index
		&& list->next->index > list->prev->index)
		reverse(stack_a, 1);
	if (stack_a->first->index > stack_a->first->next->index)
		swap(stack_a, 1);
}

short	check_if_sorted(t_stack *stack)
{
	t_list	*current;
	size_t	cur_num;

	current = stack->first->next;
	cur_num = stack->first->index;
	while (current->index != stack->first->index)
	{
		if (current->index != cur_num + 1)
			return (0);
		cur_num = current->index;
		current = current->next;
	}
	return (1);
}

short	check_ssort(t_stack *stack)
{
	size_t	index;
	t_list	*list;

	index = 0;
	list = stack->first;
	while (list->index != 0)
	{
		list = list->next;
		index++;
	}
	while (list->next->index != 0)
	{
		if (!((list->index + 1) == list->next->index))
			return (0);
		list = list->next;
	}
	while (index)
	{
		rotate(stack, 1);
		index--;
	}
	return (1);
}
