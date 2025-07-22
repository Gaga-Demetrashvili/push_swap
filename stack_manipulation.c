#include "push_swap.h"

void	radix_sort(t_stack *a, t_stack *b)
{
	int i;
	int j;
	int mux_num = a->capacity;
	int max_bits = 0;

	while ((mux_num >> max_bits) != 0)
		max_bits++;
	
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->capacity)
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
	int *arr;
	int *indexed_arr;

	arr = validate_input(argv + 1, size);
	if (!arr)
	{
		printf("%s\n", "Error");
		return;
	}
	// print_int_arr(arr, size);
	indexed_arr = sort_and_indexsize_int_tab(arr, size);
	// printf("%s", "sorted arr - ");
	// print_int_arr(arr, size); // 1 0 2 4 3 5
	free(arr);
	if (!indexed_arr)
	{
		printf("%s\n", "Error");
		return;
	}
	// printf("%s", "indexed stack - ");
	// print_int_arr(indexed_arr, size); // 1 0 2 4 3 5
	int *arr_b = (int *)malloc(sizeof(int) * size);


	// At the begining stack_a is full that's why size and capacity are same
	t_stack *stack_a = create_stack(indexed_arr, size, size, 'a');
	// At the begining stack_b should be empty,
	// capacity will be same as stack_a's
	t_stack *stack_b = create_stack(arr_b, 0, size, 'b');

	radix_sort(stack_a, stack_b);
	// printf("%s", "sorted indexed stack - ");
	// print_int_arr(indexed_arr, size); // 1 0 2 4 3 5
	// print_int_arr(stack_a->arr, size);

	// tests
	// stack_operations_tests(stack_a, stack_b);
}