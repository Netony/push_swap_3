#include "push_swap.h"

int	rra(t_vars *vars)
{
	return (rrotate(&(vars->a)));
}

int	rrb(t_vars *vars)
{
	return (rrotate(&(vars->b)));
}

int	rrr(t_vars *vars)
{
	return (rra(vars) || rrb(vars));
}
