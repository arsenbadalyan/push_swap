#include "push_swap.h"

void rotate_together(StackInterface *s1, StackInterface *s2)
{
    rotate(s1);
    rotate(s2);
}

void rotate(StackInterface *stack)
{
    if (stack->top > 1 && stack->first && stack->last)
        stack->first = stack->first->next;
}