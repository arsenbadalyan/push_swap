#include "push_swap.h"

size_t length(char *str)
{
    size_t len;

    len = 0;
    while (str[len])
        len++;
    return (len);
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
            if (!check(splited[i]))
            {
                free_me(0, splited);
                return (0);
            }
            size++;
            i++;
        }
        free_me(0, splited);
    }
    return (size);
}

short check(char *str)
{
    long long atoi_check;
    size_t len;
    size_t i;

    i = 0;
    str = check_zeros(str);
    len = length(str);
    if (!len || len >= 12)
        return (0);
    if ((str[i] == '+' || str[i] == '-') && str[i + 1])
        i++;
    while (str[i])
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return (0);
        i++;
    }
    atoi_check = my_atoi(str);
    if (atoi_check < -2147483648 || atoi_check > 2147483647)
        return (0);
    return (1);
}
