#include "push_swap.h"

void	stack_operations_tests(t_stack *stack_a, t_stack *stack_b)
{
	return ;

	// swap a
	stack_a->swap(stack_a);
	print_int_arr(stack_a->arr, stack_a->size);

	// push b
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);
	// push(stack_a, stack_b);

	print_both_stacks(stack_a, stack_b);
	// ---------------- //
	// push(stack_b, stack_a);
	// push(stack_b, stack_a);
	// push(stack_b, stack_a);
	// push(stack_b, stack_a);
	// push(stack_b, stack_a);
	// push(stack_b, stack_a);

	// ft_printf("%s", "stack_a - ");
	// print_int_arr(stack_a->arr, stack_a->size);
	// ft_printf("%s", "stack_b - ");
	// print_int_arr(stack_b->arr, stack_b->size);

	// rotate rr
	stack_a->rotate(stack_a);
	stack_b->rotate(stack_b);

	print_both_stacks(stack_a, stack_b);

	// rrotate rrr
	stack_a->rrotate(stack_a);
	stack_b->rrotate(stack_b);

	print_both_stacks(stack_a, stack_b);

	// swap a
	stack_a->swap(stack_a);
	print_int_arr(stack_a->arr, stack_a->size);

	// push a
	push(stack_b, stack_a);
	push(stack_b, stack_a);
	push(stack_b, stack_a);

	print_both_stacks(stack_a, stack_b);
}