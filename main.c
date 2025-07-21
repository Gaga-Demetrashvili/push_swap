#include "push_swap.h"

int	main(int argc, char **argv)
{
	int size;
	if (argc == 1) // If no args are specified return to prompt
		return (0);
	size = argc - 1;
	stack_controller(size, argv);
	return (0);
}