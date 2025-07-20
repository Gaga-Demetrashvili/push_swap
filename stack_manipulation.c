#include "push_swap.h"

int	ascending(int a, int b)
{
	return (a <= b);
}

int	is_arr_sorted(int *arr, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (!ascending(arr[i - 1], arr[i]))
			return (0);
		i++;
	}
	return (1);
}

void	stack_controller(int *arr_a, int *arr_b, int size)
{
	// At the begining stack_a is full that's why size and capacity are same
	t_stack *stack_a = create_stack(arr_a, size, size);
	// At the begining stack_b should be empty,
	// capacity will be same as stack_a's
	t_stack *stack_b = create_stack(arr_b, 0, size);

	// printf("%s\n", is_arr_sorted(stack_a->arr,
	// 		size) ? "is sorted" : "is not sorted");

	// case 1 7 5 3 9 8
	// we should prob check: if arr is already sorted, we can terminate process,
	// but for now I am focused on sort logic and I skip this step
	int half_of_stack = size / 2;
	while (half_of_stack--)
	{
		push(stack_a, stack_b);
		print_both_stacks(stack_a, stack_b);
	}

	// tests
	stack_operations_tests(stack_a, stack_b);
}