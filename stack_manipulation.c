#include "push_swap.h"

typedef struct s_stack
{
    int *arr;
    size_t size;
    size_t capacity;
    void (*swap)(struct s_stack *self);
    void (*rotate)(struct s_stack *self);
    void (*rrotate)(struct s_stack *self);
}   t_stack;

static void swap(t_stack *stack)
{
    int tmp;

    if (stack->size <= 1)
        return;
    tmp = (stack->arr)[0];
    (stack->arr)[0] = (stack->arr)[1];
    (stack->arr)[1] = tmp;
}

// dir (direction) 1 will be up, 0 will be down
void shift_elements(t_stack *stack, size_t dir)
{
    int i;
    if (dir)
    {
        i = 1;
        while(i < stack->size)
        {
            stack->arr[i - 1] = stack->arr[i];
            i++;
        }
    }
    else
    {
        if (stack->size == 0)
            return;
        i = stack->size - 1;
        while (i >= 0)
        {
            stack->arr[i + 1] = stack->arr[i];
            i--;
        }   
    }
}

static void rotate(t_stack *stack)
{
    int tmp = stack->arr[0];
    shift_elements(stack, 1);
    stack->arr[stack->size - 1] = tmp;
}

static void rrotate(t_stack *stack)
{
    int tmp = stack->arr[stack->size - 1];
    stack->size--; // because in idea I am removing element from bottom
    shift_elements(stack, 0);
    stack->size++;
    stack->arr[0] = tmp;
}

static t_stack *create_stack(int *arr, size_t size, size_t capacity)
{
    t_stack *stack;
    
    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->arr = arr;
    stack->size = size;
    stack->capacity = capacity;
    stack->swap = swap;
    stack->rotate = rotate;
    stack->rrotate = rrotate;
    return (stack);
}

// do not know if I will need to check if stack-a's size < capacity so it was not full;
static void push(t_stack *a, t_stack *b)
{
    int tmp;
    if (a->size == 0)
        return;
    tmp = a->arr[0];
    if (a->size == 0 || b->size == b->capacity)
        return;
    shift_elements(a, 1);
    a->size--;
    shift_elements(b, 0);
    b->size++;
    b->arr[0] = tmp;
}

void stack_controller(int *arr_a, int *arr_b, size_t size)
{
    t_stack *stack_a = create_stack(arr_a, size, size); // At the begining stack_a is full that's why size and capacity are same
    t_stack *stack_b = create_stack(arr_b, 0, size); // At the begining stack_b should be empty, capacity will be same as stack_a's

    // tests

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

    printf("%s", "stack_a - ");
    print_int_arr(stack_a->arr, stack_a->size);
    printf("%s", "stack_b - ");
    print_int_arr(stack_b->arr, stack_b->size);
    // ---------------- //
    // push(stack_b, stack_a);
    // push(stack_b, stack_a);
    // push(stack_b, stack_a);
    // push(stack_b, stack_a);
    // push(stack_b, stack_a);
    // push(stack_b, stack_a);
    
    // printf("%s", "stack_a - ");
    // print_int_arr(stack_a->arr, stack_a->size);
    // printf("%s", "stack_b - ");
    // print_int_arr(stack_b->arr, stack_b->size);

    // rotate rr
    stack_a->rotate(stack_a);
    stack_b->rotate(stack_b);

    printf("%s", "stack_a - ");
    print_int_arr(stack_a->arr, stack_a->size);
    printf("%s", "stack_b - ");
    print_int_arr(stack_b->arr, stack_b->size);

    // rrotate rrr
    stack_a->rrotate(stack_a);
    stack_b->rrotate(stack_b);

    printf("%s", "stack_a - ");
    print_int_arr(stack_a->arr, stack_a->size);
    printf("%s", "stack_b - ");
    print_int_arr(stack_b->arr, stack_b->size);

    // swap a
    stack_a->swap(stack_a);
    print_int_arr(stack_a->arr, stack_a->size);

    // push a
    push(stack_b, stack_a);
    push(stack_b, stack_a);
    push(stack_b, stack_a);
    
    printf("%s", "stack_a - ");
    print_int_arr(stack_a->arr, stack_a->size);
    printf("%s", "stack_b - ");
    print_int_arr(stack_b->arr, stack_b->size);
    return;
}