/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:33:30 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:33:34 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	*stack_to_array(t_stack *stack)
{
	int	i;
	int	n;
	int	*array;

	n = ft_stsize(stack);
	array = (int *)malloc(sizeof(int) * n);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		array[i++] = stack->data;
		stack = stack->next;
	}
	return (array);
}

int	ft_arrcpy(int *dst, int *src, int start, int end)
{
	while (start < end)
	{
		dst[start] = src[start];
		start++;
	}
	return (start);
}
