#include "push_swap.h"
#include "get_next_line.h"

void print(char **list)
{
	size_t i;

	i = 0;
	puts("-----------------");
	while (list[i+2])
	{
		printf("%s", list[i]);
		i++;
	}
	printf("%s\n", list[i]);
}

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

char **copy_list(char **list, char *line)
{
	char **new_list;
	size_t i;

	i = 1;
	while(list[i])
		i++;
	new_list = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(list[i])
	{
		new_list[i] = ft_strdup(list[i]);
		i++;
	}
	new_list[i] = ft_strdup(line);
	i++;
	new_list[i] = NULL;
	free(list);
	// free_me(0, list);
	return (new_list);
}

char **get_lines(char *line, char **list)
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
	// print(list);
	list = copy_list(list, line);
	// print(list);
	return (list);
}

int main(int argc, char **argv)
{
	char *line;
	char **list;

	list = (char **)malloc(sizeof(char *));
	while(list)
		list = get_lines(line, list);
	print(list);
	return (0);
}