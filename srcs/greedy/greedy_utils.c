/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 19:37:59 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/15 19:38:00 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index_of_value(t_stack *stack, int value);

typedef struct s_gred
{
	int	ra;
	int	rb;
	int	min;
}	t_gred;

void	greedy_update(t_gred *gred, int ra, int rb)
{
	gred->ra = ra;
	gred->rb = rb;
	gred->min = ft_abs_sum(ra, rb);
}

int	greedy_check(t_gred *gred, int ra, int rb)
{
	if (gred->min > ft_abs_sum(ra, rb))
		return (1);
	return (0);
}

int	greedy_count_1(t_vars *vars, int value)
{
	int	index;
	int	count;

	index = get_index_of_value(vars->a, value);
	count = get_rotate(index, ft_stsize(vars->a));
	return (count);
}

int	greedy_count_2(t_vars *vars, int index)
{
	int	count;

	count = get_rotate(i, ft_stsize(vars->b));
	return (count);
}

int	get_index_of_value(t_stack *stack, int value)
{
	int		index;
	int		min;
	int		cur;
	int		i;
	int		n;

	n = ft_stsize(stack);
	min = value - stack->data;
	i = 0;
	while (i < n)
	{
		cur = value - stack->data;
		if (cur > 0)
		{
			if (min > cur)
			{
				min = cur;
				index = i;
			}
		}
		stack = stack->next;
		i++;
	}
	return (i);
}
