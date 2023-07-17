#ifndef GREEDY_H
# define GREEDY_H

#include "push_swap.h"

typedef struct	s_gred
{
	int	ra;
	int	rb;
	int	min;
}	t_gred;

void	greedy_check_n_update(t_vars *vars, t_gred *gred, int index, int value);

int		greedy_check(t_gred *gred, int ra, int rb);
void	greedy_update(t_gred *gred, int ra, int rb);

int		greedy_count_1(t_vars *vars, int value);
int		greedy_count_2(t_vars *vars, int index);

#endif
