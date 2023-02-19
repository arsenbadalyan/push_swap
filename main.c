#include "push_swap.h"

// Main function to apply user arguments
int main(int argc, char **argv)
{
	int argument_size;
	int *list;
	Stack *stack_a;
	Stack *stack_b;
	StackInterface *istack_a;
	StackInterface *istack_b;

	istack_a = (StackInterface *)malloc(sizeof(*istack_a));
	if(!istack_a || argc <= 1)
		return (0);
	argument_size = validate_arguments(argc, argv);
	if (argc > 1 && argument_size)
	{
		list = mkarr_check_doubles(argv, argc, argument_size);
		if(!list)
			print_error();
		stack_a = create_stack(list, argument_size, istack_a);
		// while(--argument_size >= 0)
		// {
		// 	printf("arg[%d] = %d\n", argument_size, list[argument_size]);
		// }
		// free_me(&list);
	}
	else
		print_error();
	// system("leaks push_swap");
	return (0);
}