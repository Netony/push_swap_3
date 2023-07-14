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

void	move_one(t_stack *a, t_stack *b)
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

void	greedy(t_stack *a, t_stack *b)
{
	int	min;
	int	index;
	int	size;
	int	i;

	size = ft_stsize(b);
	i = 0;
	while (i < size)
	{
		
		b = b->next;
		i++;
	}
	push
}

int	greedy_count(t_stack *a, t_stack *b)
{
	int	b_rotate;
	int	a_rotate;

	b_rotate = 
}

int	greedy_rotate_b(int index, int size)
{
	if (index > size / 2)
		return (size - index);
	return (index);
}

int	
