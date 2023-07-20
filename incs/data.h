#ifndef DATA_H
# define DATA_H

# define INT_MAX 2147483647

typedef struct	s_data
{
	int	min;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int rr;
	int	rrr;
}	t_data;

int		ft_min_four_arg(int a, int b, int c, int d);
void	data_bzero(t_data *data);
t_data	*data_new(void);

int		data_get(t_data *data, char *s);

#endif
