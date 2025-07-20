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
