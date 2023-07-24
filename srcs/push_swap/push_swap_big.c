/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:24:38 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:28:26 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stack.h"

t_data	*greedy(t_vars *vars, t_stack *stack);

int	push_swap_push_all_pivot(t_vars *vars, int left)
{
	int		mid;
	int		i;
	int		size;

	size = ft_stsize(vars->a);
	mid = size / 2;
	i = 0;
	while (i++ < size - left)
	{
		if (vars->a->data < mid)
		{
			if (push_swap(vars, "pb") < 0)
				return (-1);
		}
		else
		{
			if (push_swap(vars, "pb") < 0)
				return (-1);
			if (push_swap(vars, "rb") < 0)
				return (-1);
		}
	}
	return (0);
}

int	push_swap_push_all(t_vars *vars, int left)
{
	int	n;

	n = ft_stsize(vars->a) - left;
	if (n <= 0)
		return (0);
	if (push_swap_n(vars, "pb", n) < 0)
		return (-1);
	return (0);
}

int	push_swap_greedy(t_vars *vars)
{
	int		ret;
	t_data	*data;

	while (vars->b)
	{
		data = greedy(vars, vars->b);
		ret = push_swap_data(vars, data);
		free(data);
		if (ret < 0)
			return (-1);
		ret = push_swap(vars, "pa");
		if (ret < 0)
			return (-1);
	}
	return (0);
}

int	push_swap_three(t_vars *vars, char *a)
{
	int		sort;
	int		index;
	t_stack	*stack;

	if (ft_strcmp("a", a) == 0)
		stack = vars->a;
	else
		stack = vars->b;
	sort = ft_issorted(stack);
	if (sort == 1)
	{
		index = ft_stidx_min(stack);
		if (push_swap_rotate(vars, "ra", "rra", index) < 0)
			return (-1);
	}
	else if (sort == 2)
	{
		index = ft_stidx_mid(stack);
		if (push_swap_rotate(vars, "ra", "rra", index) < 0)
			return (-1);
		if (push_swap(vars, "sa") < 0)
			return (-1);
	}
	return (sort);
}

int	push_swap_sort(t_vars *vars, char *a)
{
	int		sort;
	int		index;
	t_stack	*stack;

	if (ft_strcmp("a", a) == 0)
		stack = vars->a;
	else
		stack = vars->b;
	sort = ft_issorted(stack);
	if (sort == 1)
	{
		index = ft_stidx_min(stack);
		if (push_swap_rotate(vars, "ra", "rra", index) < 0)
			return (-1);
	}
	return (sort);
}
