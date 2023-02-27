#include "push_swap.h"

void reverse_together(t_stack *s1, t_stack *s2)
{
    reverse(s1, 0);
    reverse(s2, 0);
    print_command_adn('r', 'r', 'r');
}

void reverse(t_stack *stack, short idf)
{
    if (stack->top > 1 && stack->first && stack->last)
    {
        stack->first = stack->first->prev;
        stack->last = stack->last->prev;
    }
    if (idf)
        print_command_adn('r', 'r', stack->name);
}