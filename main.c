#include "push_swap.h"

long ft_atoi(char *num)
{
    long res;
    int sign;
    size_t i;

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

int is_arg_int(char *arg)
{
    if (arg[0] == '0' && arg[1] != '\0')
        return (0);
    size_t i;

    i = 0;
    while(arg[i])
    {
        if (arg[i] == '-' && (i != 0 || arg[1] == '\0'))
            return (0);
        if (arg[i] != '-' && (arg[i] < '0' || arg[i] > '9'))
            return (0);
        i++; 
    }
    return (1);
}

int num_sits_in_int_limit(long num)
{
    if (num < INT_MIN || num > INT_MAX)
        return (0);
    return (1);
}

int *validate_and_init_arr(char **args, int size)
{
    int *arr;
    size_t i;
    long num;

    if (!args || size == 0)
        return (NULL);
    arr = (int *)malloc(sizeof(int) * size);
    if (!arr)
        return (NULL);
    i = 0;
    while (i < size)
    {
        if (is_arg_int(args[i]) && num_sits_in_int_limit(ft_atoi(args[i])))
            arr[i] = ft_atoi(args[i]);
        else
        {
            free(arr);
            return (NULL);
        }
        i++;
    }
    return (arr);
}

int is_distinct(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while(i < size)
    {
        j = 0;
        while (j < size)
        {
            if (i != j && arr[i] == arr[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

void print_int_arr(int *arr, int size)
{
    size_t i;

    i = 0;
    while (i < size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("%c", '\n');
}

int main(int argc, char **argv)
{
    // int val_res = is_arg_int(argv[1]);
    // printf("%s\n", val_res ? "int" : "not int");

    // int res = ft_atoi(argv[1]);
    // printf("%d\n", res);

    int *arr = validate_and_init_arr(argv + 1, argc - 1);
    if (!arr)
    {
        printf("%s\n", "Error");
        return (0);
    }
    int distinct = is_distinct(arr, argc - 1);
    print_int_arr(arr, argc - 1);
    printf("%s\n", distinct ? "distinct" : "not distinct");
    return (0);
}