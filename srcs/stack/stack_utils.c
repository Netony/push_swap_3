#include "stack.h"

int	ft_stmin_index(t_stack *stack)
{
	int	min;
	int	min_index;
	int	i;
	int	size;

	min = INT_MAX;
	min_index = 0;
	size = ft_stsize(stack);
	i = 0;
	while (i < size)
	{
		if (min > stack->data)
		{
			min = stack->data;
			min_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min_index);
}

int	ft_stmax_index(t_stack *stack)
{
	int	max;
	int	max_index;
	int	i;
	int	size;

	max = INT_MIN;
	max_index = 0;
	size = ft_stsize(stack);
	i = 0;
	while (i < size)
	{
		if (max < stack->data)
		{
			max = stack->data;
			max_index = i;
		}
		stack = stack->next;
		i++;
	}
	return (max_index);
}

int	ft_stmid_index(t_stack *stack)
{
	const int	index[3] = {0, 1, 2};
	int			max;
	int			min;
	int			i;

	min = ft_stmin_index(stack);
	max = ft_stmax_index(stack);
	i = 0;
	while (i < 3)
	{
		if (index[i] == min) ;
		else if (index[i] == max) ;
		else
			return (i);
		i++;
	}
	return (-1);
}
