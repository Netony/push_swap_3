#include "push_swap.h"
#include "data.h"

static int	data_ra(t_vars *vars, int ra);
static int	data_rb(t_vars *vars, int rb);

int	data_operation(t_vars *vars, t_data *data)
{
	data_rb(vars, data->rb);
	data_ra(vars, data->ra);
	return (0);
}

static int	data_ra(t_vars *vars, int ra)
{
	while (ra)
	{
		if (ra > 0)
		{
			push_swap_ra(vars);
			ra--;
		}
		else
		{
			push_swap_rra(vars);
			ra++;
		}
	}
	return (0);
}

static int	data_rb(t_vars *vars, int rb)
{
	while (rb)
	{
		if (rb > 0)
		{
			push_swap_rb(vars);
			rb--;
		}
		else
		{
			push_swap_rrb(vars);
			rb++;
		}
	}
	return (0);
}
