/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_base_oper_3.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:09:15 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:09:15 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
