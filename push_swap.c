/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemetra <gdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:10:22 by gdemetra          #+#    #+#             */
/*   Updated: 2025/07/24 22:55:47 by gdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_mem(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	free(a);
	free(b);
}

int	check_arr(int *arr)
{
	if (!arr)
	{
		ft_printf("%s\n", "Error");
		return (1);
	}
	return (0);
}

void	push_swap(int size, char **argv)
{
	int		*arr;
	int		*indexed_arr;
	int		*arr_b;
	t_stack	*stack_a;
	t_stack	*stack_b;

	arr = validate_input(argv, size);
	if (check_arr(arr))
		return ;
	indexed_arr = sort_and_indexsize_int_tab(arr, size);
	free(arr);
	if (check_arr(indexed_arr))
		return ;
	if (1 == size)
	{
		free(indexed_arr);
		return ;
	}
	arr_b = (int *)malloc(sizeof(int) * size);
	stack_a = create_stack(indexed_arr, size, size, 'a');
	stack_b = create_stack(arr_b, 0, size, 'b');
	radix_sort(stack_a, stack_b);
	free_mem(stack_a, stack_b);
}
