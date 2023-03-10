/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 11:18:08 by arsbadal          #+#    #+#             */
/*   Updated: 2023/02/27 20:30:54 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Starting validation of user input */
size_t	validate_arguments(int argc, char **argv)
{
	size_t	i;
	size_t	size;
	char	**splited;

	size = 0;
	while (--argc)
	{
		i = 0;
		splited = splited_arr(argv[argc], ' ');
		if (!splited)
			return (0);
		while (splited[i])
		{
			if (!check(splited[i]))
			{
				free_me(0, splited);
				return (0);
			}
			size++;
			i++;
		}
		free_me(0, splited);
		splited = 0;
	}
	return (size);
}

/* Checking if there no other characters except numbers */
/* Also check given number is less then INT_MAX and bigger then INT_MIN */
short	check(char *str)
{
	long long	atoi_check;
	size_t		len;
	size_t		i;
	char		*tmp;

	i = 0;
	tmp = str;
	if ((str[i] == '+' || str[i] == '-') && str[i + 1])
		str++;
	str = check_zeros(str);
	len = length(str);
	if (!len || len >= 12)
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	atoi_check = my_atoi(tmp);
	if (atoi_check < INT_MIN || atoi_check > INT_MAX)
		return (0);
	return (1);
}
