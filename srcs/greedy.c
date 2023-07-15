#include "push_swap.h"

int	ft_abs(int a);

int	greedy(t_vars *vars)
{
	t_stack	*cur;
	int		ra;
	int		rb;
	int		min;
	int		i;

	cur = vars->b;
	while (i < )
	{
		ra = greedy_ra_count(vars, cur);
		rb = greedy_rb_count(i);
		min = ft_abs(ra) + ft_abs(rb);
		cur = cur->next;
	}
	return (0);
}

int	greedy_count(t_vars *vars, int index, int value)
{
	int	ra_count;
	int	rb_count;

	greedy_rb_count(vars, index);
	greedy_ra_count(vars, 
}

int	greedy_rb_count(t_vars *vars, int index)
{
	int	count;

	count = get_rotate(i, ft_stsize(vars->b))
	return (count);
}

int	greedy_ra_count(t_vars *vars, int value)
{
	int	index;
	int	count;

	index = get_index_of_value(vars->a, value);
	count = get_rotate(index, ft_stsize(vars->a));
	return (count);
}

int	get_index_of_value(t_stack *stack, int value)
{
	t_stack	*stack;
	int		cur;
	int		min;
	int		i;
	int		n;

	n = ft_stsize(stack);
	min = value - stack->data;
	i = 0;
	while (i < n)
	{
		cur = value - stack->data;
		if (cur > 0)
		{
			if (min > cur)
				min = cur;
		}
		stack = stack->next;
		i++;
	}
	return (ft_stidx(stack, min));
}
