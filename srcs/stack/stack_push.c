/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:07:29 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:07:43 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ft_stpush_data(t_stack **head, int data)
{
	t_stack	*new;

	new = ft_stnew(data);
	if (new == NULL)
		return (-1);
	return (ft_stpush_stack(head, new));
}

int	ft_stpush_stack(t_stack **head, t_stack *new)
{
	t_stack	*last;

	last = ft_stlast(new);
	if (*head)
	{
		new->prev = (*head)->prev;
		last->next = *head;
		new->prev->next = new;
		last->next->prev = last;
	}
	*head = new;
	return (0);
}
