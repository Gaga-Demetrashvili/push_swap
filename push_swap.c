#include "push_swap.h"

void	push_swap(int size, char **argv)
{
	int *arr;
	int *indexed_arr;

	arr = validate_input(argv, size);
	if (!arr)
	{
		ft_printf("%s\n", "Error");
		return ;
	}
	// print_int_arr(arr, size);
	indexed_arr = sort_and_indexsize_int_tab(arr, size);
	// ft_printf("%s", "sorted arr - ");
	// print_int_arr(arr, size); // 1 0 2 4 3 5
	free(arr);
	if (!indexed_arr)
	{
		ft_printf("%s\n", "Error");
		return ;
	}
	// ft_printf("%s", "indexed stack - ");
	// print_int_arr(indexed_arr, size); // 1 0 2 4 3 5
	int *arr_b = (int *)malloc(sizeof(int) * size);

	// At the begining stack_a is full that's why size and capacity are same
	t_stack *stack_a = create_stack(indexed_arr, size, size, 'a');
	// At the begining stack_b should be empty,
	// capacity will be same as stack_a's
	t_stack *stack_b = create_stack(arr_b, 0, size, 'b');

	radix_sort(stack_a, stack_b);
	// ft_printf("%s", "sorted indexed stack - ");
	// print_int_arr(indexed_arr, size); // 1 0 2 4 3 5

	// tests
	// stack_operations_tests(stack_a, stack_b);
}