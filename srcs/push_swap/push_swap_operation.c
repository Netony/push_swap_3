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

int	rra(t_vars *vars)
{
	return (rrotate(&(vars->a)));
}

int	rb(t_vars *vars)
{
	return (rotate(&(vars->b)));
}

int	rrb(t_vars *vars)
{
	return (rrotate(&(vars->b)));
}

int	sa(t_vars *vars)
{
	return (swap(&(vars->a)));
}

int	sb(t_vars *vars)
{
	return (swap(&(vars->b)));
}

int	ss(t_vars *vars)
{
	return (sa(vars) || sb(vars));
}

int	rr(t_vars *vars)
{
	return (ra(vars) || rb(vars));
}

int	rrr(t_vars *vars)
{
	return (rra(vars) || rrb(vars));
}
