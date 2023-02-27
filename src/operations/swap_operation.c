#include "push_swap.h"

void swap_together(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a, 0);
    swap(stack_b, 0);
    print_command('s', 's');
}

void swap(t_stack *stack, short idf)
{
    t_list *list;
    int tempData;
    size_t tempIndex;

    list = stack->first;
    if (!list || list->next->data == list->data)
        return;
    tempData = list->data;
    tempIndex = list->index;
    list->data = list->next->data;
    list->index = list->next->index;
    list->next->data = tempData;
    list->next->index = tempIndex;
    if (idf)
        print_command('s', stack->name);
}