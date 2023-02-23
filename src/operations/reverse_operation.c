#include "push_swap.h"

void reverse_together(StackInterface *s1, StackInterface *s2)
{
    reverse(s1);
    reverse(s2);
}

void reverse(StackInterface *stack)
{
    if (stack->top > 1 && stack->first && stack->last)
    {
        stack->first = stack->first->prev;
        stack->last = stack->last->prev;
    }
}