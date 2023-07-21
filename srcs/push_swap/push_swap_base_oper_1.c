#include "push_swap.h"

int	pa(t_vars *vars)
{
	return (push(&(vars->b), &(vars->a)));
}

int	pb(t_vars *vars)
{
	return (push(&(vars->a), &(vars->b)));
}

int	ra(t_vars *vars)
{
	return (rotate(&(vars->a)));
}

int	rb(t_vars *vars)
{
	return (rotate(&(vars->b)));
}

int	rr(t_vars *vars)
{
	return (ra(vars) || rb(vars));
}
