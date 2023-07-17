#include "push_swap.h"

int	gred_oper_ra(t_vars *vars, int ra);
int	gred_oper_rb(t_vars *vars, int ra);

int	greedy_operation(t_vars *vars, t_gred *gred)
{
	gred_oper_rb(vars, gred->rb);
	pa(vars);
	gred_oper_ra(vars, gred->ra);
	return (0);
}

int	gred_oper_ra(t_vars *vars, int ra)
{
	while (ra)
	{
		if (ra--- > 0)
			ra(vars);
		else if (ra++ < 0)
			rra(vars);
	}
	return (0);
}

int	gred_oper_rb(t_vars *vars, int ra)
{
	while (rb)
	{
		if (rb--- > 0)
			rb(vars);
		else if (rb++ < 0)
			rrb(vars);
	}
	return (0);
}
