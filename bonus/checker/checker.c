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

int ft_strncmp(const char *str1, const char *str2, size_t n)
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

	i = 0;
	while (list[i])
		i++;
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
	// free_me(0, list);
	return (new_list);
}

char **get_lines(char *line, char **list)
{
	line = get_next_line(0);
	if (!line)
		return (0);
	if (!(ft_strncmp(line, "sa", 2) || ft_strncmp(line, "sb", 2) || ft_strncmp(line, "ss", 2) || ft_strncmp(line, "pa", 2) || ft_strncmp(line, "pb", 2) || ft_strncmp(line, "ra", 2) || ft_strncmp(line, "rb", 2) || ft_strncmp(line, "rr", 2) || ft_strncmp(line, "rra", 3) || ft_strncmp(line, "rrb", 3) || ft_strncmp(line, "rrr", 3)))
	{
		free(line);
		free_me(0, list);
		free_error(0, 0);
	}
	list = copy_list(list, line);
	return (list);
}

short true_arrangement(t_stack *stack)
{
	size_t index;
	t_list *list;

	list = stack->first->next;
	index = stack->first->index;
	while(list->next->index != index)
	{
		if (list->index != (list->prev->index + 1))
			return (1);
		list = list->next;
	}
	return (0);
}

void select_function(t_stack *a, t_stack *b, char *command)
{
	if(ft_strncmp(command, "sa", 2))
		swap(a, 0);
	else if (ft_strncmp(command, "sb", 2))
		swap(b, 0);
	else if (ft_strncmp(command, "ss", 2))
		swap_together(a, b, 0);
	else if (ft_strncmp(command, "pa", 2))
		push_stack(&b, a, 0);
	else if (ft_strncmp(command, "pb", 2))
		push_stack(&a, b, 0);
	else if (ft_strncmp(command, "rra", 3))
		reverse(a, 0);
	else if (ft_strncmp(command, "rrb", 3))
		reverse(b, 0);
	else if (ft_strncmp(command, "rrr", 3))
		reverse_together(a, b, 0);
	else if (ft_strncmp(command, "ra", 2))
		rotate(a, 0);
	else if (ft_strncmp(command, "rb", 2))
		rotate(b, 0);
	else if (ft_strncmp(command, "rr", 2))
		rotate_together(a, b, 0);
}

void check_sort(t_stack *stack_a, char **commands)
{
	t_stack *stack_b;
	size_t	i;
	
	i = 0;
	stack_b = init_stack('b');
	if (!stack_b)
	{
		free_stack(stack_a);
		return;
	}
	while(commands[i])
	{
		select_function(stack_a, stack_b, commands[i]);
		i++;
	}
	if (stack_b->top || true_arrangement(stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}

short check_input(int argc, char **argv, char **commands)
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
			check_sort(istack_a, commands);
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