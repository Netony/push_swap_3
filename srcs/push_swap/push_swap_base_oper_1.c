/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_base_oper_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:09:06 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:09:07 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
