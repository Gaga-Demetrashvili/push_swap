#include "push_swap.h"

void	print_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_printf("%d ", arr[i]);
		i++;
	}
	ft_printf("%c", '\n');
}

void	print_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("%c", '\n');
	ft_printf("%s", "stack_a - ");
	print_int_arr(stack_a->arr, stack_a->size);
	ft_printf("%s", "stack_b - ");
	print_int_arr(stack_b->arr, stack_b->size);
	ft_printf("%c", '\n');
}

static size_t	ascending(int a, int b)
{
	return (a <= b);
}

static int	*arrdup(int *arr, int size)
{
	int	*new_arr;
	int	i;

	new_arr = malloc(sizeof(int) * size);
	if (!new_arr || !arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	return (new_arr);
}

static int	get_index(int *sorted_arr, int val, int size)
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

static int	indexsize_arr(int *indexed_arr, int *arr, int size)
{
	int	i;
	int	index;

	i = 0;
	while (i < size)
	{
		index = get_index(arr, indexed_arr[i], size);
		if (index == -1)
			return (0);
		indexed_arr[i] = index;
		i++;
	}
	return (1);
}

int	splitted_args_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

int	*sort_and_indexsize_int_tab(int *arr, int size)
{
	int i;
	int tmp;
	int *indexed_arr;
	int indexsisation_res;

	indexed_arr = arrdup(arr, size);
	if (!indexed_arr)
		return (NULL);
	i = 1;
	while (i < size)
	{
		if (!ascending(arr[i - 1], arr[i]))
		{
			tmp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = tmp;
			if (i > 1)
				i--;
		}
		else
			i++;
	}
	indexsisation_res = indexsize_arr(indexed_arr, arr, size);
	if (!indexsisation_res)
		return (NULL);
	return (indexed_arr);
}

void	radix_sort(t_stack *a, t_stack *b)
{
	int	i;
	int	j;
	int	mux_num;
	int	max_bits;
	int	num;

	mux_num = a->capacity;
	max_bits = 0;
	while ((mux_num >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < a->capacity)
		{
			num = a->arr[0];
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