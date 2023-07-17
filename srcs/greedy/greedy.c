#include "greedy.h"

void	greedy_check_n_update(t_vars *vars, t_gred *gred, int index, int value)
{
	int	ra;
	int	rb;

	ra = greedy_count_1(vars, index);
	rb = greedy_count_2(vars, value);
	if (greedy_check(gred, ra, rb))
		greedy_update(gred, ra, rb);
}
