#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

// validation part
long	ft_atoi(char *num);
void	print_int_arr(int *arr, int size);
int		*validate_input(char **args, int size);

// stack operations part
void stack_controller(int *arr_a, int *arr_b, size_t size);

#endif