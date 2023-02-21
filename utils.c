#include "push_swap.h"

void print_error()
{
	write(1, "Error\n", 6);
	system("leaks push_swap");
	exit(1);
}

void free_me(void *addr, char **addr_2D)
{
	int i;

	i = -1;
	if (addr_2D)
	{
		while (addr_2D[++i])
			free(addr_2D[i]);
		free(addr_2D);
		addr_2D = 0x0;
	}
	if (addr)
	{
		free(addr);
		addr = 0x0;
	}
}

char **splited_arr(char *str, char seperator)
{
	char **splited;

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