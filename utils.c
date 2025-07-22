#include "push_swap.h"

long	ft_atoi(char *num)
{
	long	res;
	int		sign;
	size_t	i;

	res = 0;
	sign = 1;
	i = 0;
	if (num[0] == '-')
	{
		sign *= -1;
		i++;
	}
	while (num[i])
	{
		res = res * 10 + (num[i] - '0');
		i++;
	}
	return (res * sign);
}

void	print_int_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("%c", '\n');
}

void	print_both_stacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("%c", '\n');
	printf("%s", "stack_a - ");
	print_int_arr(stack_a->arr, stack_a->size);
	printf("%s", "stack_b - ");
	print_int_arr(stack_b->arr, stack_b->size);
	printf("%c", '\n');
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