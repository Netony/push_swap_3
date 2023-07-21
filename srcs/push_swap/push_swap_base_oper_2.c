#include "push_swap.h"

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

