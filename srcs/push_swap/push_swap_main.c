#include "push_swap.h"
#include "../srcs/test.h"

int	push_swap_main(t_vars *vars)
{
	int	sort;
	int	ret;

	sort = push_swap_sort(vars, "a");
	if (sort == 1)
		return (0);
	push_swap_test(vars);
	ret = push_swap_move_all(vars, 3);
	push_swap_test(vars);
	if (ret < 0)
		return (-1);
	sort = push_swap_sort(vars, "a");
	if (sort < 0)
		return (-1);
	ret = push_swap_greedy(vars);
	if (ret < 0)
		return (-1);
	push_swap_test(vars);
	sort = push_swap_sort(vars, "a");
	if (sort == 1)
		return (-1);
	return (0);
}

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

int	push_swap_circular(t_vars *vars, int index)
{
	int	ret;

	ret = push_swap_min_rotate(vars, "ra", "rra", index);
	return (ret);
}
