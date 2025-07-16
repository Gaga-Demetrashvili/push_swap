#include "push_swap.h"

int	main(int argc, char **argv)
{
	int *arr = validate_input(argv + 1, argc - 1);
	if (!arr)
	{
		printf("%s\n", "Error");
		return (0);
	}
	print_int_arr(arr, argc - 1);

	return (0);
}