#include "push_swap.h"

int	push_swap_main(t_vars *vars)
{
	int	sort;
	int	ret;

	sort = push_swap_sort_three(vars, "a");
	if (sort == 1)
		return (0);
	ret = push_swap_move_all(vars, 3);
	if (ret < 0)
		return (-1);
	sort = push_swap_sort(vars, "a");
	if (sort < 0)
		return (-1);
	ret = push_swap_greedy(vars);
	if (ret < 0)
		return (-1);
	sort = push_swap_sort(vars, "a");
	if (sort == 2)
		return (-1);
	return (0);
}

int	push_swap_circular(t_vars *vars, int index)
{
	int	ret;

	ret = push_swap_min_rotate(vars, "ra", "rra", index);
	return (ret);
}
