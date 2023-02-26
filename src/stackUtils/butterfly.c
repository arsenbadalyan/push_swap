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
    butterfly_reverse(stack_a, stack_b);
}

void butterfly_reverse(StackInterface *stack_a, StackInterface *stack_b)
{
    size_t index;
    Stack *temp;

    while(stack_b->top)
    {
        index = 0;
        temp = stack_b->first;
        while(temp->index != stack_b->top - 1)
        {
            temp = temp->next;
            index++;
        }
        if(index > (stack_b->top / 2))
            while(stack_b->first->index != temp->index)
                rotate(stack_b, 1);
        else
            while(stack_b->first->index != temp->index)
                reverse(stack_b, 1);
                
        push_stack(&stack_b, stack_a);
    }
}

















