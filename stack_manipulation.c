#include "push_swap.h"

void	stack_controller(int *arr_a, int *arr_b, int size)
{
	t_stack *stack_a = create_stack(arr_a, size, size);
	// At the begining stack_a is full that's why size and capacity are same
	t_stack *stack_b = create_stack(arr_b, 0, size);
	// At the begining stack_b should be empty,
	// capacity will be same as stack_a's

	// tests
	stack_operations_tests(stack_a, stack_b);
}