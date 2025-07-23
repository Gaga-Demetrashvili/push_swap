#include "push_swap.h"

// dir (direction) 1 will be up, 0 will be down
static void	shift_elements(t_stack *stack, size_t dir)
{
	int	i;

	if (dir)
	{
		i = 1;
		while (i < stack->size)
		{
			stack->arr[i - 1] = stack->arr[i];
			i++;
		}
	}
	else
	{
		if (stack->size == 0)
			return ;
		i = stack->size - 1;
		while (i >= 0)
		{
			stack->arr[i + 1] = stack->arr[i];
			i--;
		}
	}
}

// do not know if I will need to check if stack-a's size < capacity so it was not full;
void	push(t_stack *a, t_stack *b)
{
	int	tmp;

	if (a->size == 0)
		return ;
	tmp = a->arr[0];
	if (a->size == 0 || b->size == b->capacity)
		return ;
	shift_elements(a, 1);
	a->size--;
	shift_elements(b, 0);
	b->size++;
	b->arr[0] = tmp;
	ft_printf("p%c\n", b->name);
}

void	rotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->arr[0];
	shift_elements(stack, 1);
	stack->arr[stack->size - 1] = tmp;
	ft_printf("r%c\n", stack->name);
}

void	rrotate(t_stack *stack)
{
	int	tmp;

	tmp = stack->arr[stack->size - 1];
	stack->size--; // because in idea I am removing element from bottom
	shift_elements(stack, 0);
	stack->size++;
	stack->arr[0] = tmp;
	ft_printf("%s\n", "reverse rotate");
}

void	swap(t_stack *stack)
{
	int	tmp;

	if (stack->size <= 1)
		return ;
	tmp = (stack->arr)[0];
	(stack->arr)[0] = (stack->arr)[1];
	(stack->arr)[1] = tmp;
	ft_printf("%s\n", "swap");
}

t_stack	*create_stack(int *arr, int size, int capacity, char name)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->arr = arr;
	stack->size = size;
	stack->capacity = capacity;
	stack->name = name;
	stack->swap = swap;
	stack->rotate = rotate;
	stack->rrotate = rrotate;
	return (stack);
}
