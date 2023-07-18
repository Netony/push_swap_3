#include "push_swap.h"
#include <stdio.h>
#include "stack.h"

int	get_index_of_value(t_stack *stack, int value);
int	test(int a, int b);
int	greedy_get_data_rotate(int rotate, int size);

int	ft_min(int a, int b);

int	main(void)
{
	printf("%d\n", test(3, 5));
	return (0);
}

int	test(int a, int b)
{
	return (greedy_get_data_rotate(a, b));
}
