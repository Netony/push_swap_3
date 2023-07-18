#include "greedy.h"
#include "push_swap.h"

int	get_rotate_count(int rotate, int max_index);
int	greedy_get_data_rotate(int rotate, int size);

int	get_index_of_value(t_stack *stack, int value);

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
	int		i;
	int		index;
	int		size;
	int		min;
	t_stack	*b;

	b = vars->b;
	size = ft_stsize(b);
	i = 0;
	while (i < size)
	{
		if (i == 0)
		{
			min = b->data - value;
			index = i + 1;
		}
		else if (0 < b->data - value && b->data - value < min)
		{
			min = b->data - value;
			index = i + 1;
		}
		b = b->next;
		i++;
	}
	return (index);
}

int	greedy_get_data_rotate(int rotate, int size)
{
	if (rotate > size / 2)
		rotate = rotate - size;
	return (rotate);
}
