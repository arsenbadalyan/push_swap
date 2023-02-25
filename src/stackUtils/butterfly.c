#include "push_swap.h"

int get_n(size_t size)
{
    return (1);
}

void butterfly(StackInterface *stack_a, StackInterface *stack_b)
{
    int i;

    i = get_n(stack_a->top);
    while(stack_a->top)
    {
        if(stack_a->first->index <= stack_b->top)
        {
            push_stack(&stack_a, stack_b);
            if(stack_b->top > 1)
                rotate(stack_b, 1);
        }
        else if(stack_a->first->index <= stack_b->top + i)
            push_stack(&stack_a, stack_b);
        else
            rotate(stack_a, 1);
            
    }
    print_stack(stack_a, 0, stack_a->name);
    print_stack(stack_b, 0, stack_b->name);
}