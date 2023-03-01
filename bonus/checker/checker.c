#include "push_swap.h"
#include "get_next_line.h"

void print(char **list)
{
	size_t i;

	i = 0;
	puts("-----------------");
	while (list[i])
	{
		printf("%s", list[i]);
		i++;
	}
	printf("%s\n", list[i]);
}

int ft_strcmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

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
	while (list[i])
		i++;
	new_list = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (list[i])
	{
		new_list[i] = ft_strdup(list[i]);
		i++;
	}
	new_list[i] = ft_strdup(line);
	i++;
	new_list[i] = NULL;
	// free_me(0, list);
	return (new_list);
}

char **get_lines(char *line, char **list)
{
	line = get_next_line(0);
	if (!line)
		return (0);
	if (!(ft_strcmp(line, "sa", 2) || ft_strcmp(line, "sb", 2) || ft_strcmp(line, "ss", 2) || ft_strcmp(line, "pa", 2) || ft_strcmp(line, "pb", 2) || ft_strcmp(line, "ra", 2) || ft_strcmp(line, "rb", 2) || ft_strcmp(line, "rr", 2) || ft_strcmp(line, "rra", 3) || ft_strcmp(line, "rrb", 3) || ft_strcmp(line, "rrr", 3)))
		return (0);
	list = copy_list(list, line);
	return (list);
}

void check_sort(t_stack stack_a, char **commands)
{
	t_stack *stack_b;

	stack_b = init_stack('b');
	if (!stack_b)
		return (0);
	
	free_stack(stack_a);
	free_stack(stack_b);
}

void check_input(int argc, char **argv, char **commands)
{
	int *list;
	size_t argument_size;
	t_stack *istack_a;

	istack_a = init_stack('a');
	if (!istack_a || argc <= 1)
		return (1);
	argument_size = validate_arguments(argc, argv);
	if (argument_size)
	{
		list = mkarr_check_doubles(argv, argc, argument_size);
		if (!list)
		{
			free_me(0, commands);
			free_error(istack_a, 0);
		}
		create_stack(list, argument_size, istack_a);
		if (!istack_a->has_error)
			return (1);
	}
	else
		free_error(istack_a, 0);
	free_me(0, commands);
	return (0);
}

int main(int argc, char **argv)
{
	char *line;
	char **list;
	char **temp;

	list = (char **)malloc(sizeof(char *));
	while (list)
	{
		list = get_lines(line, list);
		if (list)
			temp = list;
	}
	list = temp;
	check_input(argc, argv, list);
	return (0);
}