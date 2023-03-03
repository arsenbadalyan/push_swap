/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:04 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 20:28:28 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_together(t_stack *s1, t_stack *s2, short idf)
{
	reverse(s1, 0);
	reverse(s2, 0);
	if (idf)
		print_command_adn('r', 'r', 'r');
}

void	reverse(t_stack *stack, short idf)
{
	if (stack->top > 1 && stack->first && stack->last)
	{
		stack->first = stack->first->prev;
		stack->last = stack->last->prev;
	}
	if (idf)
		print_command_adn('r', 'r', stack->name);
}
