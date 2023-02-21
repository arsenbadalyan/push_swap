#include "push_swap.h"

void print_stack(StackInterface *stack, int all)
{
	size_t i;
	Stack *head;

	if (!stack->first)
		return;
	head = stack->first;
	i = 0;
	if (all)
	{
		while (i < stack->top)
		{
			puts("-----------");
			printf("Data:  %d\n", head[i].data);
			printf("Index: %lu\n", head[i].index);
			puts("-----------");
			i++;
		}
	}
	else
	{
		while (i < stack->top)
		{
			printf("%d\n", head[i].data);
			i++;
		}
		puts("-");
		puts("s");
	}
}

int start_sort(StackInterface *stack_a)
{
	StackInterface *stack_b;

	stack_b = (StackInterface *)malloc(sizeof(stack_b));
	if (!stack_b)
		return (0);
	print_stack(stack_a, 0);
	// swap_together(stack_a, stack_b);
	Stack *test = stack_a->first;
	// remove_el_from_stack(stack_a, test);
	// test = test->next;
	free(&test[1]);
	// free(test->next);
	print_stack(stack_a, 0);
	return (1);
}

// Main function to apply user arguments
int main(int argc, char **argv)
{
	int *list;
	size_t argument_size;
	StackInterface *istack_a;

	istack_a = (StackInterface *)malloc(sizeof(*istack_a));
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