#ifndef DATA_H
# define DATA_H

typedef struct	s_data
{
	int	ra;
	int	rb;
}	t_data;

t_data	*data_new(int a, int b);
void	data_del(t_data *data);
void	data_substitute(t_data *a, t_data *b);
int		data_sum(t_data *data);

#endif
