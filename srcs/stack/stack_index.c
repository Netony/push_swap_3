/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:53:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 19:57:53 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stidx_mid(t_stack *stack)
{
	const int	index[3] = {0, 1, 2};
	int			max;
	int			min;
	int			i;

	min = ft_stidx_min(stack);
	max = ft_stidx_max(stack);
	i = 0;
	while (i < 3)
	{
		if (index[i] == min)
			;
		else if (index[i] == max)
			;
		else
			return (i);
		i++;
	}
	return (-1);
}

int	ft_stidx_min(t_stack *stack)
{
	int	i;
	int	size;
	int	min;
	int	index;

	i = 0;
	index = 0;
	size = ft_stsize(stack);
	if (stack)
		min = stack->data;
	while (i < size)
	{
		if (stack->data < min)
		{
			min = stack->data;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	ft_stidx_max(t_stack *stack)
{
	int	i;
	int	size;
	int	max;
	int	index;

	i = 0;
	index = 0;
	size = ft_stsize(stack);
	if (stack)
		max = stack->data;
	while (i < size)
	{
		if (stack->data > max)
		{
			max = stack->data;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	ft_stidx_larger(t_stack *stack, int value)
{
	int	index;
	int	i;
	int	size;
	int	min;

	size = ft_stsize(stack);
	index = 0;
	min = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (stack->data > value)
		{
			if (stack->data < min)
			{
				min = stack->data;
				index = i;
			}
		}
		stack = stack->next;
		i++;
	}
	if (min == INT_MAX)
		index = ft_stidx_min(stack);
	return (index);
}
