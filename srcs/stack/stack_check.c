/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:39:14 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:07:53 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_issorted(t_stack *stack)
{
	int	sort;
	int	i;
	int	size;

	size = ft_stsize(stack);
	sort = 0;
	i = 0;
	if (size == 1)
	{
		i++;
		sort++;
	}
	while (i < size)
	{
		if (stack->data > stack->next->data)
			sort++;
		i++;
		stack = stack->next;
	}
	return (sort);
}

int	ft_issorted_checker(t_stack *stack)
{
	int	sort;

	sort = ft_issorted(stack);
	if (sort == 1 && ft_stidx_min(stack) == 0)
		return (1);
	return (0);
}
