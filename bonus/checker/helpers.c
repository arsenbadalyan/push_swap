#include "push_swap.h"

short true_arrangement(t_stack *stack)
{
    size_t index;
    t_list *list;

    list = stack->first->next;
    index = stack->first->index;
    while (list->next->index != index)
    {
        if (list->index != (list->prev->index + 1))
            return (1);
        list = list->next;
    }
    return (0);
}

void select_function(t_stack *a, t_stack *b, char *command)
{
    if (ft_strncmp(command, "sa", 2))
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
    size_t i;

    i = 0;
    stack_b = init_stack('b');
    if (!stack_b)
    {
        free_stack(stack_a);
        return;
    }
    while (commands[i])
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
