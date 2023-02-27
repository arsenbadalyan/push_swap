/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:09 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/27 20:25:24 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_together(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
	print_command('s', 's');
}

void	swap(t_stack *stack, short idf)
{
	t_list	*list;
	int		temp_data;
	size_t	temp_index;

	list = stack->first;
	if (!list || list->next->data == list->data)
		return ;
	temp_data = list->data;
	temp_index = list->index;
	list->data = list->next->data;
	list->index = list->next->index;
	list->next->data = temp_data;
	list->next->index = temp_index;
	if (idf)
		print_command('s', stack->name);
}
