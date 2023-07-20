#include "data.h"
#include "push_swap.h"

static int	greedy_renew_first(t_data *data, int ra, int rb);
static int	greedy_renew_second(t_data *data, int rra, int rrb);
static int	greedy_renew_third(t_data *data, int rra, int rb);
static int	greedy_renew_forth(t_data *data, int ra, int rrb);

void	greedy_renew(t_data *data, t_vars *vars, int index, int value)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	min;

	ra = ft_stidx_near(vars->a, value);
	rra = ft_stsize(vars->a) - data->ra;
	rb = index;
	rrb = ft_stsize(vars->b) - data->rb;
	min = ft_min_four_arg(ft_max(ra, rb), ft_max(rra, rrb), rra + rb, ra + rrb);
	if (min < data->min)
	{
		data_bzero(data);
		if (min == ft_max(ra, rb))
			greedy_renew_first(data, ra, rb);
		else if (min == ft_max(rra, rrb))
			greedy_renew_second(data, rra, rrb);
		else if (min == rra + rb)
			greedy_renew_third(data, rra, rb);
		else if (min == ra + rrb)
			greedy_renew_forth(data, ra, rrb);
		data->min = min;
	}
}

static int	greedy_renew_first(t_data *data, int ra, int rb)
{
	data->rr = ft_min(ra, rb);
	if (ra > rb)
		data->ra = ra - rb;
	else
		data->rb = rb - ra;
	return (0);
}

static int	greedy_renew_second(t_data *data, int rra, int rrb)
{
	data->rrr = ft_min(rra, rrb);
	if (rra > rrb)
		data->rra = rra - rrb;
	else
		data->rrb = rrb - rra;
	return (0);
}

static int	greedy_renew_third(t_data *data, int rra, int rb)
{
	data->rra = rra;
	data->rb = rb;
	return (0);
}

static int	greedy_renew_forth(t_data *data, int ra, int rrb)
{
	data->ra = ra;
	data->rrb = rrb;
	return (0);
}
