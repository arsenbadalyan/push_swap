#include "push_swap.h"

void select_algorithm(StackInterface *stack_a, StackInterface *stack_b)
{
    if (!stack_a || !stack_b)
        return;
    if (stack_a->top == 1)
        return;
    if (stack_a->top == 2)
    {
        if (stack_a->first->data > stack_a->last->data)
            swap(stack_a, 1);
        return;
    }
    if (check_if_sorted(stack_a))
        return;
    if (stack_a->top == 3)
    {
        sort_3(stack_a, stack_b);
        return;
    }
}

void sort_3(StackInterface *stack_a, StackInterface *stack_b)
{
    int min_index;
    size_t index;

    push_stack(&stack_a, stack_b);
    select_algorithm(stack_a, stack_b);
    index = stack_b->first->index;
    push_stack(&stack_b, stack_a);
    if (index < stack_a->first->next->index)
        return;
    if (index > stack_a->last->index)
    {
        rotate(stack_a, 1);
        return;
    }
    swap(stack_a, 1);
}

short check_if_sorted(StackInterface *stack)
{
    Stack *current;
    int cur_num;

    current = stack->first->next;
    cur_num = stack->first->index;
    while (current->index != stack->first->index)
    {
        if (current->index != cur_num + 1)
            return (0);
        cur_num = current->index;
        current = current->next;
    }
    return (1);
}