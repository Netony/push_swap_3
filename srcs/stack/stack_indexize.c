/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_indexize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:38:42 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:38:43 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "stack.h"

static int	ft_arrayidx(int value, int *arr, int size);

int	stack_indexize(t_stack *stack)
{
	int	i;
	int	size;
	int	*array;

	size = ft_stsize(stack);
	if (size == 0)
		return (0);
	array = stack_to_array(stack);
	if (array == NULL)
		return (-1);
	if (ft_arrsort(array, size) < 0)
		return (-1);
	i = 0;
	while (i++ < size)
	{
		stack->data = ft_arrayidx(stack->data, array, size);
		if (stack->data < 0)
			return (-1);
		stack = stack->next;
	}
	free(array);
	return (0);
}

static int	ft_arrayidx(int value, int *arr, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		if (arr[index] == value)
			return (index);
		index++;
	}
	return (-1);
}
