#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int validate_arguments(int argc, char **argv)
{
	int i;

	while (--argc)
	{
		i = 0;
		while (argv[argc][i])
		{
			if (!(argv[argc][i] >= '0' && argv[argc][i] <= '9') && !(i == 0 && argv[argc][i] == '-' && argv[argc][i + 1]))
				return (0);
			i++;
		}
	}
	return (1);
}

// Main function to apply user arguments
int main(int argc, char **argv)
{
	if (argc > 1 && validate_arguments(argc, argv))
	{
		printf("%d\n", my_atoi(argv[1]));
	}
	else
		print_error();
	return (0);
}