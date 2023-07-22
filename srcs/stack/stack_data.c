/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:04:11 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:04:12 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*ft_stlast(t_stack *head)
{
	if (head == NULL)
		return (NULL);
	return (head->prev);
}

int	ft_stsize(t_stack *head)
{
	int		size;
	t_stack	*last;

	if (head == NULL)
		return (0);
	size = 1;
	last = ft_stlast(head);
	while (last != head)
	{
		last = last->prev;
		size++;
	}
	return (size);
}
