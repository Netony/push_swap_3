/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_base_oper_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:09:10 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:09:32 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
