#include "push_swap.h"

void print_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

void free_me(void *addr)
{
	if (addr)
	{
		free(addr);
		addr = 0x0;
	}
}

int my_atoi(char *number)
{
	int sign;
	unsigned int result;
	sign = 1;
	result = 0;
	if (*number == '-')
	{
		sign = -1;
		number++;
	}
	while (*number)
	{
		result = ((result * 10) + (*number - '0'));
		number++;
	}
	return ((int)(result * sign));
}

void mkarr_check_doubles(char **argv, int size)
{
	int *num_list;
	int temp;

	temp = size;
	num_list = (int *)malloc(sizeof(int) * size);
	if (!num_list)
		print_error();
	while (--size > 0)
	{
		num_list[size - 1] = my_atoi(argv[size]);
		while (size <= i)
		{
			if (num_list[size] ==)
		}
	}
}