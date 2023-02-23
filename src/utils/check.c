#include "push_swap.h"

char *check_zeros(char *number)
{
	if (*number == '0' && *(number + 1))
	{
		while (*number && *number == '\0')
			number++;
		return (number);
	}
	return (number);
}

int *mkarr_check_doubles(char **argv, int argc, size_t size)
{
	int *num_list;
	size_t temp;
	long long i;
	char **splited;

	temp = size - 1;
	num_list = (int *)malloc(sizeof(int) * size);
	if (!num_list)
		print_error();
	while (--argc > 0)
	{
		i = 0;
		splited = splited_arr(argv[argc], ' ');
		if (!splited)
			return (0);
		while (splited[i])
			i++;
		while (i > 0)
		{
			i--;
			num_list[temp] = my_atoi(splited[i], 0);
			temp--;
		}
		free_me(0, splited);
	}
	if (!check_doubles(num_list, size))
		return (NULL);
	return (num_list);
}

int check_doubles(int *num_list, size_t size)
{
	size_t i;
	size_t temp;

	i = 0;
	while (i < size - 1)
	{
		temp = i + 1;
		while (temp < size)
		{
			if (num_list[i] == num_list[temp])
			{
				i = -1;
				free_me(num_list, 0);
				return (0);
			}
			temp++;
		}
		i++;
	}
	return (1);
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
	number = check_zeros(number);
	while (*number)
	{
		if (*number < '0' || *number > '9')
		{
			free_me(0, splited);
			print_error();
		}
		result = ((result * 10) + (*number - '0'));
		number++;
	}
	return ((int)(result * sign));
}

size_t validate_arguments(int argc, char **argv)
{
	size_t i;
	size_t size;
	char **splited;

	size = 0;
	while (--argc)
	{
		i = 0;
		splited = splited_arr(argv[argc], ' ');
		if (!splited)
			return (0);
		while (splited[i])
		{
			my_atoi(splited[i], splited);
			size++;
			i++;
		}
		free_me(0, splited);
	}
	return (size);
}