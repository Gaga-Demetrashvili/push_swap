#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		*arr;
	int		size;
	int		capacity;
	void	(*swap)(struct s_stack *self);
	void	(*rotate)(struct s_stack *self);
	void	(*rrotate)(struct s_stack *self);
}			t_stack;

// validation part
long		ft_atoi(char *num);
void		print_int_arr(int *arr, int size);
void		print_both_stacks(t_stack *stack_a, t_stack *stack_b);
int			*validate_input(char **args, int size);
int			*sort_int_tab(int *arr, int size);

// stack operations part
t_stack		*create_stack(int *arr, int size, int capacity);
void		swap(t_stack *stack);
void		rotate(t_stack *stack);
void		rrotate(t_stack *stack);
void		push(t_stack *a, t_stack *b);

// I think main sorting logic will go here (might rename file and method later)
void		stack_controller(int *arr_a, int *arr_b, int size);

// method for testing if operations work properly
void		stack_operations_tests(t_stack *stack_a, t_stack *stack_b);

#endif