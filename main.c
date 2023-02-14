#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

char **splited_arr(char *str, char seperator)
{
	char **splited;

	splited = ft_split(str, ' ');
	if(!splited)
		return (0);
	if(!splited[0])
	{
		free_me(0, splited);
		return (0);
	}
	return (splited);
}

int validate_arguments(int argc, char **argv)
{
	int i;
	int	size;
	char *check;
	char **splited;

	size = 0;
	while (--argc)
	{
		i = -1;
		splited = splited_arr(argv[argc], ' ');
		if(!splited)
			return (0);
		while (splited[++i])
		{
			my_atoi(splited[i], splited);
			size++;
		}
		free_me(0, splited);
	}
	return (size);
}

// Main function to apply user arguments
int main(int argc, char **argv)
{
	int argument_size;
	int *list;

	argument_size = validate_arguments(argc, argv);
	if (argc > 1 && argument_size)
	{
		list = mkarr_check_doubles(argv, argc, argument_size);
		while(--argument_size >= 0)
		{
			printf("arg[%d] = %d\n", argument_size, list[argument_size]);
		}
	}
	else
		print_error();
	return (0);
}