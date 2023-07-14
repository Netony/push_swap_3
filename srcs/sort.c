#include "push_swap.h"

int	get_mid(t_stack *stack)
{
	int	min;
	int	max;

	min = stack->data;
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		else if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return ((max + min) / 2);
}

void	move_one(t_vars	*vars)
{
	int	n;
	int	i;

	n = ft_stsize(a) - 3;
	if (n < 0)
		return ;
	i = 0;
	while (i < n)
	{
		ft_stpush(&a, &b);
		i++;
	}
}

void	greedy(t_vars *vars)
{
	int	min;
	int	count;
	int	i;

	n = ft_stsize(b);
	i = 0;
	while (i < n)
	{
		count = 0;
		count = greddy_rotate_b(i, n);
		count = greddy_rotate_a
		b = b->next;
		i++;
	}
	push
}

int	greedy_rotate_a(int data, t_stack *a, )
{
	int	i;
	int	n;

	n = ft_stsize(a);
	i = 0;
	while (i < )
	{
		
	}
}

int	rr_or_rrr(int index, int size)
{
	if (index > size / 2)
		return (size - index);
	return (index);
}

int	
