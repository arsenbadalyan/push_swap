#include "get_next_line.h"
#include <stdio.h>

int	ft_strcmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int get_lines(char *line)
{
	line = get_next_line(0);
	if (!line)
		return (0);
	if (!(ft_strcmp(line, "sa", 2) || ft_strcmp(line, "sb", 2)
		|| ft_strcmp(line, "ss", 2) || ft_strcmp(line, "pa", 2)
		|| ft_strcmp(line, "pb", 2) || ft_strcmp(line, "ra", 2)
		|| ft_strcmp(line, "rb", 2) || ft_strcmp(line, "rr", 2)
		|| ft_strcmp(line, "rra", 3) || ft_strcmp(line, "rrb", 3)
		|| ft_strcmp(line, "rrr", 3)))
		return (0);	
	return (1);
}

int main(int argc, char **argv)
{
	char *line;

	while(get_lines(line))
	{
		
	}
	return (0);
}