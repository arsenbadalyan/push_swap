/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:07 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/03 20:28:53 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_together(t_stack *s1, t_stack *s2, short idf)
{
	rotate(s1, 0);
	rotate(s2, 0);
	if (idf)
		print_command('r', 'r');
}

void	rotate(t_stack *stack, short idf)
{
	if (stack->top > 1 && stack->first && stack->last)
	{
		stack->first = stack->first->next;
		stack->last = stack->last->next;
	}
	if (idf)
		print_command('r', stack->name);
}
