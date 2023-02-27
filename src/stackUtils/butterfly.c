#include "push_swap.h"

void butterfly(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	if(stack_a->top <= 14)
	{
		small_sort(stack_a, stack_b);
		return;
	}
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

void butterfly_reverse(t_stack *stack_a, t_stack *stack_b)
{
	size_t index;
	t_list *temp;

	while(stack_b->top)
	{
		index = 0;
		temp = stack_b->first;
		while(temp->index != stack_b->top - 1)
		{
			temp = temp->next;
			index++;
		}
		go_top(stack_b, temp);
		push_stack(&stack_b, stack_a);
	}
}

void small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int min;
	t_list *temp;
	t_list *s_min;

	while(stack_a->top > 3)
	{
		temp = stack_a->first->next;
		min = stack_a->first->index;
		s_min = stack_a->first;
		while(temp->index != stack_a->first->index)
		{
			if(temp->index < min)
			{
				s_min = temp;
				min = temp->index;
			}
			temp = temp->next;
		}
		go_top(stack_a, s_min);
		push_stack(&stack_a, stack_b);
	}
	sort_3(stack_a);
	while(stack_b->top)
		push_stack(&stack_b, stack_a);
}

void go_top(t_stack *stack, t_list *cur)
{
	size_t queue;
	t_list *head;

	head = stack->first;
	queue = 0;
	while (head->index != cur->index)
	{
		head = head->next;
		queue++;
	}
	if (queue > (stack->top / 2))
		while (stack->first->index != cur->index)
			reverse(stack, 1);
	else
		while (stack->first->index != cur->index)
			rotate(stack, 1);
}















