#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		capacity;
	char	name;
	void	(*swap)(struct s_stack *self);
	void	(*rotate)(struct s_stack *self);
	void	(*rrotate)(struct s_stack *self);
}			t_stack;

// validation part
long		ft_atoi_ps(char *num);
void		print_int_arr(int *arr, int size);
void		print_both_stacks(t_stack *stack_a, t_stack *stack_b);
int			*validate_input(char **args, int size);
int			*sort_and_indexsize_int_tab(int *arr, int size);
int			splitted_args_size(char **args);

// stack operations part
t_stack		*create_stack(int *arr, int size, int capacity, char name);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rrotate(t_stack *stack);
void		push(t_stack *a, t_stack *b);

// I think main sorting logic will go here (might rename file and method later)
void		stack_controller(int size, char **argv);

// method for testing if operations work properly
void		stack_operations_tests(t_stack *stack_a, t_stack *stack_b);

#endif