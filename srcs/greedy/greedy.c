#include "greedy.h"

t_data	*greedy_init(t_vars *vars);

t_data	*greedy(t_vars *vars)
{
	t_data	new;
	t_data	*min;
	t_stack	*b;
	int		i;
	int		n;

	min = greedy_init(vars);
	if (min == NULL)
		return (NULL);
	b = vars->b;
	n = ft_stsize(b);
	i = 0;
	while (i < n)
	{
		greedy_get_data(&new, vars, i, b->data);
		if (data_sum(&new) < data_sum(min))
			data_substitute(min, &new);
		b = b->next;
		i++;
	}
	return (min);
}

t_data	*greedy_init(t_vars *vars)
{
	t_data	*new;
	int		index;
	int		value;
	
	index = 0;
	value = vars->b->data;
	new = data_new(0, 0);
	if (new == NULL)
		return (NULL);
	greedy_get_data(new, vars, index, value);
	return (new);
}
