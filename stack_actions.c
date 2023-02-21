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
		stack->next->prev = stack->prev;
		stack->prev->next = stack->next;
	}
	istack->top--;
	printf("%d\n", stack->data);
	free(stack);
	stack = 0x0;
}
