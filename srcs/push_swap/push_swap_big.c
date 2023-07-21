#include "push_swap.h"
#include "stack.h"

int	push_swap_move_all(t_vars *vars, int n)
{
	int	i;
	int	ret;

	n = ft_stsize(vars->a) - n;
	if (n <= 0)
		return (0);
	i = 0;
	while (i++ < n)
	{
		ret = push_swap(vars, "pb");
		if (ret < 0)
			return (-1);
	}
	return (ret);
}

int	push_swap_greedy(t_vars *vars)
{
	int		ret;
	t_data	*data;

	ret = push_swap_move_all(vars, 3);
	if (ret < 0)
		return (-1);
	while (vars->b)
	{
		data = greedy(vars, vars->b);
		ret = push_swap_data(vars, data);
		if (ret < 0)
			return (-1);
		ret = push_swap(vars, "pa");
		if (ret < 0)
			return (-1);
		free(data);
	}
	return (0);
}

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
		index = ft_stmin_index(stack);
		ret = push_swap_circular(vars, index);
	}
	else if (sort == 2)
	{
		index = ft_stmid_index(stack);
		ret = push_swap_min_rotate(vars, "ra", "rra", index);
		if (ret < 0)
			return (-1);
		ret = push_swap(vars, "sa");
	}
	return (sort);
}

int	push_swap_sort_three(t_vars *vars, char *a)
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
		index = ft_stmin_index(stack);
		ret = push_swap_circular(vars, index);
	}
	return (sort);
}
