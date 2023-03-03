/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:29:15 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 20:29:41 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	size_t	i;
	t_list	*head;

	if (stack && stack->top)
	{
		head = stack->first;
		i = 0;
		while (i < stack->top)
		{
			printf("|%lu|\n", head->index);
			head = head->next;
			i++;
		}
		puts("---");
		printf(" %c\n", stack->name);
	}
}

t_stack	*init_stack(char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->first = NULL;
	stack->last = NULL;
	stack->top = 0;
	stack->name = name;
	stack->has_error = 0;
	return (stack);
}
