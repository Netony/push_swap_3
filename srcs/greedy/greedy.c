#include "greedy.h"

void	greedy_renew(t_data *data, t_vars *vars, int index, int value);

t_data	*greedy(t_vars *vars)
{
	t_data	*data;
	t_stack	*b;
	int		i;
	int		size;

	data = data_new();
	if (data == NULL)
		return (NULL);
	b = vars->b;
	size = ft_stsize(b);
	i = 0;
	while (i < size)
	{
		greedy_renew(data, vars, i, b->data);
		b = b->next;
		i++;
	}
	return (data);
}
