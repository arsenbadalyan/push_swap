#include "push_swap.h"

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
	puts("empty");
	if (!stack)
		return;
	stack->first = NULL;
	stack->last = NULL;
}

void remove_el_from_stack(StackInterface *istack, Stack *stack)
{
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
	}
	istack->top--;
	free_me(stack, 0);
}

void add_el_to_stack(StackInterface *istack, Stack *stack)
{
	Stack *copy;

	copy = (Stack *)malloc(sizeof(*copy));
	if (!copy)
		return; // TODO: clean all logic
	copy = stack;
	istack->top++;
	if (!istack->first)
	{
		istack->first = copy;
		istack->last = copy;
		return;
	}
	istack->first->prev = copy;
	istack->last->next = copy;
	copy->next = istack->first;
	copy->prev = istack->last;
	istack->first = copy;
}