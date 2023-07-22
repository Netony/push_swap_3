/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_renew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:55:19 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:02:56 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "push_swap.h"

static int	greedy_renew_1(t_data *data, int ra, int rb);
static int	greedy_renew_2(t_data *data, int rra, int rrb);
static int	greedy_renew_3(t_data *data, int rra, int rb);
static int	greedy_renew_4(t_data *data, int ra, int rrb);

void	greedy_renew(t_data *data, t_vars *vars, int index, int value)
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	min;

	ra = ft_stidx_larger(vars->a, value);
	rra = ft_stsize(vars->a) - ra;
	rb = index;
	rrb = ft_stsize(vars->b) - rb;
	min = ft_min_4(ft_max(ra, rb), ft_max(rra, rrb), rra + rb, ra + rrb);
	if (min < data->min)
	{
		data_bzero(data);
		if (min == ft_max(ra, rb))
			greedy_renew_1(data, ra, rb);
		else if (min == ft_max(rra, rrb))
			greedy_renew_2(data, rra, rrb);
		else if (min == rra + rb)
			greedy_renew_3(data, rra, rb);
		else
			greedy_renew_4(data, ra, rrb);
		data->min = min;
	}
}

static int	greedy_renew_1(t_data *data, int ra, int rb)
{
	data->rr = ft_min(ra, rb);
	if (ra > rb)
		data->ra = ra - rb;
	else
		data->rb = rb - ra;
	return (0);
}

static int	greedy_renew_2(t_data *data, int rra, int rrb)
{
	data->rrr = ft_min(rra, rrb);
	if (rra > rrb)
		data->rra = rra - rrb;
	else
		data->rrb = rrb - rra;
	return (0);
}

static int	greedy_renew_3(t_data *data, int rra, int rb)
{
	data->rra = rra;
	data->rb = rb;
	return (0);
}

static int	greedy_renew_4(t_data *data, int ra, int rrb)
{
	data->ra = ra;
	data->rrb = rrb;
	return (0);
}
