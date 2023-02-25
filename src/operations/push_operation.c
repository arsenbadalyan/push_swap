#include "push_swap.h"

void push_stack(StackInterface **fromStack, StackInterface *toStack)
{
	StackInterface *from_stack;

	from_stack = *fromStack;
	if (!from_stack->first)
		return;
	// puts("------------------------------------");
	push(toStack, from_stack->first);
	// print_stack(from_stack, 0, from_stack->name);
    // print_stack(toStack, 0, toStack->name);
	pop(from_stack, &from_stack->first);
	// print_stack(from_stack, 0, from_stack->name);
    // print_stack(toStack, 0, toStack->name);
	print_command('p', toStack->name);
}