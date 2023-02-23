#include "push_swap.h"

void push_stack(StackInterface **fromStack, StackInterface *toStack)
{
	StackInterface *from_stack;

	from_stack = *fromStack;
	if (!from_stack->first)
		return;
	push(toStack, from_stack->first);
	pop(from_stack, &from_stack->first);
}