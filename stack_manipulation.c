#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int mux_num = a->size;
	int max_bits = 0;

	while ((mux_num >> max_bits) != 0)
		max_bits++;
	
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->size)
		{
			int num = a->arr[0];
			if (((num >> i) & 1) == 1)
				a->rotate(a);
			else
				push(a, b);
			j++;
		}
		while (b->size > 0)
			push(b, a);
		i++;
	}
}

void	stack_controller(int size, char **argv)
{
	int *og_arr;
	int *working_arr;

	og_arr = validate_input(argv + 1, size);
	print_int_arr(og_arr, size);
	working_arr = arrdup(og_arr, size);
	if (!og_arr || !working_arr)
	{
		printf("%s\n", "Error");
		// return (0);
	}
	int res = sort_and_indexsize_int_tab(og_arr, working_arr, size);
	printf("%s", "og arr - ");
	print_int_arr(og_arr, size); // 1 0 2 4 3 5
	printf("%s", "working arr - ");
	print_int_arr(working_arr, size); // 1 0 2 4 3 5

	if (!res)
	{
		printf("%s\n", "Error");
		// return (0);
	}
	// printf("%s", "initial stack - ");
	// print_int_arr(working_arr, size); // 1 0 2 4 3 5
	int *arr_b = (int *)malloc(sizeof(int) * size);


	// At the begining stack_a is full that's why size and capacity are same
	t_stack *stack_a = create_stack(working_arr, size, size);
	// At the begining stack_b should be empty,
	// capacity will be same as stack_a's
	t_stack *stack_b = create_stack(arr_b, 0, size);

	radix_sort(stack_a, stack_b);
	// print_int_arr(stack_a->arr, size);

	// tests
	// stack_operations_tests(stack_a, stack_b);
}