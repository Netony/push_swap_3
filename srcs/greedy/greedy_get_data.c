#include "stack.h"
#include "greedy.h"
#include "push_swap.h"

int	greedy_get_data_rotate(int rotate, int size);
int	greedy_get_index_by_value(t_stack *stack, int value);
int	greedy_count_rb(t_vars *vars, int index);
int	greedy_count_ra(t_vars *vars, int value);

void	greedy_get_data(t_data *gred, t_vars *vars, int index, int value)
{
	int	ra;
	int	rb;

	ra = greedy_count_ra(vars, value);
	rb = greedy_count_rb(vars, index);
	gred->ra = ra;
	gred->rb = rb;
}

int	greedy_count_rb(t_vars *vars, int index)
{
	return (greedy_get_data_rotate(index, ft_stsize(vars->b)));
}

int	greedy_count_ra(t_vars *vars, int value)
{
	int	index;

	index = ft_stidx_near(vars->a, value);
	return (greedy_get_data_rotate(index, ft_stsize(vars->a)));

}

int	greedy_get_data_rotate(int rotate, int size)
{
	if (rotate > size / 2)
		rotate = rotate - size;
	return (rotate);
}
