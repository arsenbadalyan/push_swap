/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arsbadal <arsbadal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:25:10 by arsbadal          #+#    #+#             */
/*   Updated: 2023/03/04 21:33:33 by arsbadal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	if (str1[i] == '\n' || !str1[i])
		return (1);
	return (0);
}

char	**copy_list(char **list, char *line)
{
	char	**new_list;
	size_t	i;

	i = 0;
	while (list[i])
	{	
		i++;
	}
	new_list = (char **)malloc(sizeof(char *) * (i + 2));
	i = 0;
	while (list[i])
	{
		new_list[i] = ft_strdup(list[i]);
		i++;
	}
	new_list[i] = ft_strdup(line);
	i++;
	new_list[i] = NULL;
	free_me((void *)&line, list);
	return (new_list);
}

char	**get_lines(char *line, char **list)
{
	line = get_next_line(0);
	if (!line)
		return (0);
	if (!(ft_strncmp(line, "sa", 2) || ft_strncmp(line, "sb", 2)
			|| ft_strncmp(line, "ss", 2) || ft_strncmp(line, "pa", 2)
			|| ft_strncmp(line, "pb", 2) || ft_strncmp(line, "ra", 2)
			|| ft_strncmp(line, "rb", 2) || ft_strncmp(line, "rr", 2)
			|| ft_strncmp(line, "rra", 3) || ft_strncmp(line, "rrb", 3)
			|| ft_strncmp(line, "rrr", 3)))
	{
		free(line);
		free_error(0, 0);
	}
	list = copy_list(list, line);
	return (list);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	**list;
	char	**temp;

	line = NULL;
	if (argc < 2)
		return (0);
	if (quick_check(argc, argv))
		return (write(1, "Error\n", 6));
	list = (char **)malloc(sizeof(char *));
	list[0] = NULL;
	temp = list;
	while (list)
	{
		list = get_lines(line, list);
		if (list)
			temp = list;
	}
	list = temp;
	check_input(argc, argv, list);
	free_me(0, list);
	return (0);
}
