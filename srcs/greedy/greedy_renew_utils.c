#include "data.h"
#include "lib.h"

int	ft_min_4(int a, int b, int c, int d)
{
	return (ft_min(ft_min(a, b), ft_min(c, d)));
}

void	data_bzero(t_data *data)
{
	data->min = 0;
	data->ra = 0;
	data->rb = 0;
	data->rra = 0;
	data->rrb = 0;
	data->rr = 0;
	data->rrr = 0;
}

t_data	*data_new(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data_bzero(data);
	data->min = INT_MAX;
	return (data);
}

int	data_get(t_data *data, char *s)
{
	if (ft_strcmp(s, "ra") == 0)
		return (data->ra);
	else if (ft_strcmp(s, "rb") == 0)
		return (data->rb);
	else if (ft_strcmp(s, "rra") == 0)
		return (data->rra);
	else if (ft_strcmp(s, "rrb") == 0)
		return (data->rrb);
	else if (ft_strcmp(s, "rrr") == 0)
		return (data->rrr);
	else if (ft_strcmp(s, "rr") == 0)
		return (data->rr);
	else
		return (-1);
}
