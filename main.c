#include "push_swap.h"

int	main(int argc, char **argv)
{
	int size;

	// If no args are specified or we have empty string as arg, return to prompt
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (0);
	if (2 == argc)
	{
		argv = ft_split(argv[1], ' ');
		size = splitted_args_size(argv);
	}
	else
	{
		argv = argv + 1;
		size = argc - 1;
	}
	push_swap(size, argv);
	return (0);
}