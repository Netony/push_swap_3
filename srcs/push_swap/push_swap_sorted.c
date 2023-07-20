#include "push_swap.h"
#include "stack.h"
#include "../srcs/test.h"

int	min_index(t_stack *stack);
int	unsorted_index(t_stack *stack);

int	push_swap_sort(t_vars *vars, char *a)
{
	int		sort;
	int		index;
	int		ret;
	t_stack	*stack;

	if (ft_strcmp("a", a) == 0)
		stack = vars->a;
	else
		stack = vars->b;
	sort = ft_issorted(stack);
	if (sort == 1)
	{
		index = min_index(stack);
		ret = push_swap_circular(vars, index);
	}
	else if (sort == 2)
	{
		index = unsorted_index(stack);
		ret = push_swap_min_rotate(vars, "ra", "rra", index);
		if (ret < 0)
			return (-1);
		ret = push_swap(vars, "sa");
	}
	return (sort);
}

int	min_index(t_stack *stack)
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

int	unsorted_index(t_stack *stack)
{
	int	i;
	int	size;
	int	min;

	size = ft_stsize(stack);
	min = ft_stmin(stack);
	i = 0;
	while (i < size)
	{
		if (stack->data > stack->next->data)
		{
			if (stack->next->data != min)
				return (i);
		}
		i++;
		stack = stack->next;
	}
	return (-1);
}
