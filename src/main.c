#include "push_swap.h"

void print_stack(StackInterface *stack, int all, char stack_name)
{
	// size_t i;
	// Stack *head;

	// head = stack->first;
	// i = 0;
	// if (all && stack->first)
	// {
	// 	while (i < stack->top)
	// 	{
	// 		puts("-----------");
	// 		printf("Data:  %d\n", head->data);
	// 		printf("Index: %lu\n", head->index);
	// 		puts("-----------");
	// 		i++;
	// 		head = head->next;
	// 	}
	// }
	// else
	// {
	// 	while (i < stack->top)
	// 	{
	// 		printf("|%d|\n", head->data);
	// 		head = head->next;
	// 		i++;
	// 	}
	// 	puts("---");
	// 	printf(" %c\n", stack_name);
	// }
}

StackInterface *init_stack(char name)
{
	StackInterface *stack;

	stack = (StackInterface *)malloc(sizeof(StackInterface));
	if(!stack)
		return (NULL);
	stack->first = NULL;
	stack->last = NULL;
	stack->top = 0;
	stack->name = name;
	return (stack);
}

int start_sort(StackInterface *stack_a)
{
	StackInterface *stack_b;

	stack_b = init_stack('b');
	if (!stack_b)
		return (0);
	// print_stack(stack_a, 0, stack_a->name);
	// print_stack(stack_b, 0, stack_b->name);
	select_algorithm(stack_a, stack_b);
	// print_stack(stack_a, 0, stack_a->name);
	// print_stack(stack_b, 0, stack_b->name);
	return (1);
}

// Main function to apply user arguments
int main(int argc, char **argv)
{
	int *list;
	size_t argument_size;
	StackInterface *istack_a;

	istack_a = init_stack('a');
	if (!istack_a || argc <= 1)
		return (1);
	argument_size = validate_arguments(argc, argv);
	if (argument_size)
	{
		list = mkarr_check_doubles(argv, argc, argument_size);
		if (!list)
			print_error();
		create_stack(list, argument_size, istack_a);
		if (!start_sort(istack_a))
			return (1);
	}
	else
		print_error();
	// system("leaks push_swap");
	return (0);
}