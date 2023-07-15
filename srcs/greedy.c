#include "push_swap.h"

void	greedy_check_n_update(t_vars *vars, t_gred *gred, int index, int value);
void	greedy_update(t_gred *gred, int ra, int rb);
int		greedy_check(t_gred *gred, int ra, int rb);
int		greedy_count_1(t_vars *vars, int value);
int		greedy_count_2(t_vars *vars, int index);

typedef struct	s_gred
{
	int	ra;
	int	rb;
	int	min;
}	t_gred;

t_gred	*greedy(t_vars *vars)
{
	t_stack	*b;
	t_gred	*gred;
	int		n;
	int		i;

	gred = (t_gred *)malloc(sizeof(t_gred));
	b = vars->b;
	n = ft_stsize(b);
	i = 0;
	while (i < n)
	{
		greedy_check_n_update(vars, &gred, i, b->data);
		i++;
		b = b->next;
	}
	return (gred);
}

void	greedy_check_n_update(t_vars *vars, t_gred *gred, int index, int value)
{
	int	ra;
	int	rb;

	ra = greedy_count_1(vars, index);
	rb = greedy_count_2(vars, value);
	if (greedy_check(gred, ra, rb))
			greedy_update(gred, ra, rb);
}
