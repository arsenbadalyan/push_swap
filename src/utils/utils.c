/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:30:16 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/04 00:52:44 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_error(t_stack *a, t_stack *b)
{
	write(2, "Error\n", 6);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	system("leaks checker");
	exit(1);
}

size_t	length(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	free_me(void **addr, char **addr_2D)
{
	size_t	i;

	i = 0;
	if (addr_2D)
	{
		while (addr_2D[i])
		{
			free(addr_2D[i]);
			i++;
		}
		free(addr_2D);
		addr_2D = 0x0;
	}
	if (addr)
	{
		free(*addr);
		*addr = 0x0;
	}
}

char	**splited_arr(char *str, char seperator)
{
	char	**splited;

	splited = ft_split(str, seperator);
	if (!splited)
		return (0);
	if (!splited[0])
	{
		free_me(0, splited);
		return (0);
	}
	return (splited);
}
