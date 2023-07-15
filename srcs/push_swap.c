/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:43:04 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/15 14:05:12 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push_swap(t_vars *vars)
{
	int	pivot;

	pivot = greedy_pivot(vars);
	ps_pa_all(vars);
	while (vars->b)
		greedy(vars);
	return (0);
}

int	ps_pivot(t_vars *vars)
{
	int	min;
	int	max;

	min = stack->data;
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		else if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return ((max + min) / 2);
}

void	greedy_move_to_b(t_vars	*vars)
{
	int	n;
	int	i;

	n = ft_stsize(a) - 3;
	if (n < 0)
		return ;
	i = 0;
	while (i < n)
	{
		ps_push(&a, &b);
		i++;
	}
}

void	greedy_move_to_a(t_vars *vars)
{
	int	min;
	int	count;
	int	i;

	n = ft_stsize(b);
	i = 0;
	while (i < n)
	{
		count = 0;
		count = mta_rotate_b(i, n);
		count = mta_rotate_a(i, n);
		b = b->next;
		i++;
	}
}

int	get_rotate(int index, int size)
{
	if (index > size / 2)
		return (size - index);
	return (index);
}
