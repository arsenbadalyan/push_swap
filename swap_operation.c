#include "push_swap.h"

void swap_together(StackInterface *stack_a, StackInterface *stack_b)
{
    swap_stack(stack_a);
    swap_stack(stack_b);
}

void swap_stack(StackInterface *stack)
{
    Stack *list;
    int tempData;
    size_t tempIndex;

    if (!stack->first || list->next->data == list->data)
        return;
    list = stack->first;
    tempData = list->data;
    tempIndex = list->index;
    list->data = list->next->data;
    list->index = list->next->index;
    list->next->data = tempData;
    list->next->index = tempIndex;
}