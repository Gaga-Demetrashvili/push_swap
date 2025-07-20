#include "push_swap.h"

int	get_index(int *sorted_arr, int val, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == val)
			return (i);
		i++;
	}
	return (-1);
}

int	indexsize_arr(int *arr, int *sorted_arr, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = get_index(sorted_arr, arr[i], size);
		if (index == -1)
			return (0);
		arr[i] = index;
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int size;
	if (argc == 1) // If no args are specified return to prompt
		return (0);
	size = argc - 1;
	int *arr_a = validate_input(argv + 1, size);
	if (!arr_a)
	{
		printf("%s\n", "Error");
		return (0);
	}
	int *sorted_arr = sort_int_tab(arr_a, size);
	if (!sorted_arr)
	{
		printf("%s\n", "Error");
		return (0);
	}
	int res = indexsize_arr(arr_a, sorted_arr, size);
	if (!res)
	{
		printf("%s\n", "Error");
		return (0);
	}
	printf("%s", "initial stack - ");
	print_int_arr(arr_a, size); // 1 0 2 4 3 5
	int *arr_b = (int *)malloc(sizeof(int) * size);
	stack_controller(arr_a, arr_b, size);
	printf("%s", "sorted stack - ");
	print_int_arr(arr_a, size);

	return (0);
}