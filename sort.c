/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdemetra <gdemetra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 16:23:38 by gdemetra          #+#    #+#             */
/*   Updated: 2025/07/24 22:54:43 by gdemetra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_and_indexsize_int_tab(int *arr, int size)
{
	int	i;
	int	tmp;
	int	*indexed_arr;
	int	indexsisation_res;

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
			i = 1;
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
			if (((a->arr[0] >> i) & 1) == 1)
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

void sort_three(t_stack *a)
{
	int top = a->arr[0];
	int mid = a->arr[1];
	int bot = a->arr[2];

	if (top > mid && mid < bot && top < bot)
		a->swap(a);
	else if (top > mid && mid > bot)
	{
		a->swap(a);
		a->rrotate(a);
	}
	else if (top > mid && mid < bot && top > bot)
		a->rotate(a);
	else if (top < mid && mid > bot && top < bot)
	{
		a->swap(a);
		a->rotate(a);
	}
	else if (top < mid && mid > bot && top > bot)
		a->rrotate(a);
}

static int index_of_smallest(t_stack *stack)
{
	int min = stack->arr[0];
	int index = 0;
	int i = 1;

	while (i < stack->size)
	{
		if (stack->arr[i] < min)
		{
			min = stack->arr[i];
			index = i;
		}
		i++;
	}
	return index;
}

void sort_five(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		int min_index = index_of_smallest(a);
		while (min_index != 0)
		{
			if (min_index <= a->size / 2)
				a->rotate(a);
			else
				a->rrotate(a);
			min_index = index_of_smallest(a);
		}
		push(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		push(b, a);
}