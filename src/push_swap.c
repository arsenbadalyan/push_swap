/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:17:52 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/04 00:52:50 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	start_sort(t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = init_stack('b');
	if (!stack_b)
		return (0);
	sel_alg(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (1);
}

// Main function to apply user arguments
int	main(int argc, char **argv)
{
	int		*list;
	size_t	argument_size;
	t_stack	*istack_a;

	istack_a = init_stack('a');
	if (!istack_a || argc <= 1)
		return (1);
	argument_size = validate_arguments(argc, argv);
	if (argument_size)
	{
		list = mkarr_check_doubles(argv, argc, argument_size);
		if (!list)
			free_error(istack_a, 0);
		create_stack(list, argument_size, istack_a);
		if (istack_a->has_error || !start_sort(istack_a))
			return (1);
	}
	else
		free_error(istack_a, 0);
	return (0);
}
