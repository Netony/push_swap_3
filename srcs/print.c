#include "stack.h"
#include "push_swap.h"
#include <stdio.h>

int	push_swap_test(t_vars *vars)
{
	t_stack	*a;
	t_stack	*b;
	int	data1;
	int	data2;
	int	n;
	int	i;

	a = vars->a;
	b = vars->b;
	printf("==========PUSH_SWAP_TEST==========\n");
	printf("%5s | %5s\n", "A", "B");
	printf("%5s | %5s\n", "-----", "-----");
	n = ft_max(ft_stsize(a), ft_stsize(b));
	i = 0;
	while (i < n)
	{
		if (ft_stsize(a) <= i && ft_stsize(b) <= i)
			break ;
		if (i >= ft_stsize(a))
			data1 = 0;
		else
			data1 = a->data;
		if (i >= ft_stsize(b))
			data2 = 0;
		else
			data2 = b->data;
		printf("%5d | %5d\n", data1, data2);
		if (a)
			a = a->next;
		if (b)
			b = b->next;
		i++;
	}
	return (0);
}

int	ft_stprint(t_stack *stack)
{
	int	i;
	int	size;

	size = ft_stsize(stack);
	i = 0;
	while (i < size)
	{
		printf("stack[%d]: %d\n", i, stack->data);
		stack = stack->next;
		i++;
	}
	return (0);
}

int	ft_dataprint(t_data *data)
{
	printf("data--------------\n");
	printf("ra: %d\n", data->ra);
	printf("rb: %d\n", data->rb);
	printf("rra: %d\n", data->rra);
	printf("rrb: %d\n", data->rrb);
	printf("rr: %d\n", data->rr);
	printf("rr: %d\n", data->rrr);
	printf("min: %d\n", data->min);
	return (0);
}
