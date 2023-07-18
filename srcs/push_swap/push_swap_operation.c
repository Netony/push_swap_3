#include "push_swap.h"

int	push_swap_pa(t_vars *vars)
{
	return (push(&(vars->b), &(vars->a)));
}

int	push_swap_pb(t_vars *vars)
{
	return (push(&(vars->a), &(vars->b)));
}

int	push_swap_ra(t_vars *vars)
{
	return (rotate(&(vars->a)));
}

int	push_swap_rra(t_vars *vars)
{
	return (rrotate(&(vars->a)));
}

int	push_swap_rb(t_vars *vars)
{
	return (rotate(&(vars->b)));
}

int	push_swap_rrb(t_vars *vars)
{
	return (rrotate(&(vars->b)));
}

int	push_swap_sa(t_vars *vars)
{
	return (swap(&(vars->a)));
}

int	push_swap_sb(t_vars *vars)
{
	return (swap(&(vars->b)));
}

int	push_swap_ss(t_vars *vars)
{
	return (push_swap_sa(vars) || push_swap_sb(vars));
}

int	push_swap_rr(t_vars *vars)
{
	return (push_swap_ra(vars) || push_swap_rb(vars));
}

int	push_swap_rrr(t_vars *vars)
{
	return (push_swap_rra(vars) || push_swap_rrb(vars));
}
