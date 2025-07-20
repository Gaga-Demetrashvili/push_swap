#include "push_swap.h"

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
	printf("%s", "initial stack - ");
	print_int_arr(arr_a, size);
	int *arr_b = (int *)malloc(sizeof(int) * size);
	stack_controller(arr_a, arr_b, size);
	printf("%s", "sorted stack - ");
	print_int_arr(arr_a, size);

	return (0);
}