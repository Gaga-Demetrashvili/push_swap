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
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	return (new_arr);
}

int	*sort_int_tab(int *arr, int size)
{
	int *sorted_arr;
	int i;
	int tmp;

	i = 1;
	sorted_arr = arrdup(arr, size);
	if (!sorted_arr)
		return (NULL);
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
	return (sorted_arr);
}