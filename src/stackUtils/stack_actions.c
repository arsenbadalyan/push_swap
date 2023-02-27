#include "push_swap.h"

void clone_stack(t_list *dest, t_list *src, int isAll)
{
	dest->data = src->data;
	dest->index = src->index;
	if (isAll)
	{
		dest->next = src->next;
		dest->prev = src->prev;
		return;
	}
	dest->next = NULL;
	dest->prev = NULL;
}

void free_stack(t_stack *stack)
{
	if(stack->top > 0)
	{
		while(stack->top)
			pop(stack, &stack->first);
	}
	free(stack);
}

void make_stack_empty(t_stack *stack)
{
	if (!stack)
		return;
	stack->first = NULL;
	stack->last = NULL;
}

void pop(t_stack *istack, t_list **p_stack)
{
	t_list *stack;

	stack = *p_stack;
	if (!istack || !stack)
		return;
	if (stack->next->data == stack->data)
		make_stack_empty(istack);
	else
	{
		if (istack->first->data == stack->data)
			istack->first = stack->next;
		else if (istack->last->data == stack->data)
			istack->last = stack->prev;
		stack->next->prev = stack->prev;
		stack->prev->next = stack->next;
	}
	istack->top--;
	free_me((void *)&stack, 0);
}

void push(t_stack *istack, t_list *stack)
{
	t_list *copy;

	copy = (t_list *)malloc(sizeof(*copy));
	if (!copy)
	{
		istack->has_error = 1;
		return;
	}
	clone_stack(copy, stack, 0);
	istack->top++;
	if (!istack->first)
	{
		istack->first = copy;
		istack->last = copy;
		istack->first->next = istack->first;
		istack->first->prev = istack->first;
		return;
	}
	istack->first->prev = copy;
	istack->last->next = copy;
	copy->next = istack->first;
	copy->prev = istack->last;
	istack->first = copy;
}