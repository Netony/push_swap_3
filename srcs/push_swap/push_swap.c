/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:03:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:28:26 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap_main(t_vars *vars)
{
	if (push_swap_sort(vars, "a") == 1)
		return (0);
	if (push_swap_push_all_pivot(vars, 3) < 0)
		return (-1);
	if (push_swap_three(vars, "a") < 0)
		return (-1);
	if (push_swap_greedy(vars) < 0)
		return (-1);
	if (push_swap_sort(vars, "a") < 0)
		return (-1);
	return (0);
}
