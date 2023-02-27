/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:08:14 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/27 21:08:15 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_command(char first, char sec)
{
	write(1, &first, 1);
	write(1, &sec, 1);
	write(1, "\n", 1);
}

void	print_command_adn(char first, char sec, char additional)
{
	write(1, &first, 1);
	write(1, &sec, 1);
	write(1, &additional, 1);
	write(1, "\n", 1);
}
