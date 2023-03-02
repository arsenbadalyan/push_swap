/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:22:01 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/27 20:23:09 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_stack **fromStack, t_stack *toStack, short idf)
{
	t_stack	*from_stack;

	from_stack = *fromStack;
	if(idf)
		print_command('p', toStack->name);
	if (!from_stack->first)
		return ;
	push(toStack, from_stack->first);
	pop(from_stack, &from_stack->first);
	if (from_stack->has_error)
		free_error(from_stack, toStack);
}
