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
	if (stack_a->top == 3)
	{
		sort_3(stack_a);
		return;
	}
	if (check_if_sorted(stack_a) || check_ssort(stack_a))
		return;
	butterfly(stack_a, stack_b);
}

void sort_3(StackInterface *stack_a)
{
	int min_index;
	size_t index;
	Stack *list;

	list = stack_a->first;
	if(list->index > list->next->index && list->index > list->prev->index)
		rotate(stack_a, 1);
	else if(list->next->index > list->index && list->next->index > list->prev->index)
		reverse(stack_a, 1);
	if(stack_a->first->index > stack_a->first->next->index)
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

short check_ssort(StackInterface *stack)
{
	size_t index;
	Stack *list;

	index = 0;
	list = stack->first;
	while(list->index != 0)
	{
		list = list->next;
		index++;
	}
	while(list->next->index != 0)
	{
		if(!((list->index + 1) == list->next->index))
			return (0);
		list = list->next;
	}
	while(index)
	{
		rotate(stack, 1);
		index--;
	}
	return (1);
}

