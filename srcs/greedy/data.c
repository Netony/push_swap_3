#include "data.h"
#include "lib.h"

t_data	*data_new(int a, int b)
{
	t_data	*new;

	new = (t_data *)malloc(sizeof(t_data));
	if (new == NULL)
		return (NULL);
	new->ra = a;
	new->rb = b;
	return (new);
}

void	data_del(t_data *data)
{
	free(data);
}

void	data_substitute(t_data *a, t_data *b)
{
	a->ra = b->ra;
	a->rb = b->rb;
}

int	data_sum(t_data *data)
{
	return (ft_abs(data->ra) + ft_abs(data->rb));
}
