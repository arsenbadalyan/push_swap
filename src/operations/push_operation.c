#include "push_swap.h"

void push_stack(t_stack **fromStack, t_stack *toStack)
{
	t_stack *from_stack;

	from_stack = *fromStack;
	if (!from_stack->first)
		return;
	push(toStack, from_stack->first);
	pop(from_stack, &from_stack->first);
	print_command('p', toStack->name);
	if(from_stack->has_error)
		free_error(from_stack, toStack);
}