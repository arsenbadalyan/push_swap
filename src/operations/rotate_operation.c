#include "push_swap.h"

void rotate_together(t_stack *s1, t_stack *s2)
{
    rotate(s1, 0);
    rotate(s2, 0);
    print_command('r', 'r');
}

void rotate(t_stack *stack, short idf)
{
    if (stack->top > 1 && stack->first && stack->last)
    {
        stack->first = stack->first->next;
        stack->last = stack->last->next;
    }
    if (idf)
        print_command('r', stack->name);
}