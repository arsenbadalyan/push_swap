#include "push_swap.h"

void print_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

void free_me(void *addr, char **addr_2D)
{
	int i;

	i = -1;
	if(addr_2D)
	{
		while(addr_2D[++i])
			free(addr_2D[i]);
		free(addr_2D);
	}
	if (addr)
	{
		free(addr);
		addr = 0x0;
	}
}

int my_atoi(char *number, char **splited)
{
	int sign;
	unsigned int result;

	sign = 1;
	result = 0;
	if (*number == '-')
		sign = -1;
	if (*number == '-' || *number == '+')
		number++;
	while (*number)
	{
		if(*number < '0' || *number > '9')
		{
			free_me(0, splited);
			print_error();
		}
		result = ((result * 10) + (*number - '0'));
		number++;
	}
	return ((int)(result * sign));
}

int *mkarr_check_doubles(char **argv, int argc, int size)
{
	int *num_list;
	int temp;
	int i;
	char **splited;

	temp = size - 1;
	// printf("%d\n", temp);
	num_list = (int *)malloc(sizeof(int) * size);
	if (!num_list)
		print_error();
	while(--argc > 0)
	{
		i = 0;
		splited = splited_arr(argv[argc], ' ');
		if(!splited)
			return (0);
		while(splited[i])
			i++;
		while(--i >= 0)
		{
			num_list[temp] = my_atoi(splited[i], 0);
			temp--;
		}
	}
	// i = 0;
	// while(i < size - 1)
	// {
	// 	temp = i + 1;
	// 	while(temp < size)
	// 	{
	// 		if(num_list[i] == num_list[temp])
	// 		{
	// 			free_me(num_list, 0);
	// 			return (0);
	// 		}
	// 		temp++;
	// 	}
	// 	i++;
	// }
	return (num_list);
}










