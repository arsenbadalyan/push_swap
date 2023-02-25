#include "push_swap.h"

void clone_stack(Stack *dest, Stack *src, int isAll)
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

void free_stack(StackInterface *stack)
{
	Stack *list;
	int i;

	i = 0;
	list = stack->first;
	if (!list)
		return;
	while (list[i].data != stack->first->data && i != 0)
	{
		free((list + i));
		i++;
	}
	free(list);
}

void make_stack_empty(StackInterface *stack)
{
	if (!stack)
		return;
	stack->first = NULL;
	stack->last = NULL;
}

void pop(StackInterface *istack, Stack **p_stack)
{
	Stack *stack;

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

void push(StackInterface *istack, Stack *stack)
{
	Stack *copy;

	copy = (Stack *)malloc(sizeof(*copy));
	if (!copy)
		return; // TODO: clean all logic
	// printf("%d - %lu\n", stack->data, stack->index);
	clone_stack(copy, stack, 0);
	// printf("%d - %lu\n", copy->data, copy->index);
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