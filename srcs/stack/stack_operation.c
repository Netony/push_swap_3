/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:04:35 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:04:36 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	push(t_stack **from, t_stack **to)
{
	if (*from == NULL)
		return (-1);
	return (ft_stpush_data(to, ft_stpop(from)));
}

int	rotate(t_stack **head)
{
	if (*head)
		*head = (*head)->next;
	return (0);
}

int	rrotate(t_stack **head)
{
	if (*head)
		*head = (*head)->prev;
	return (0);
}

int	swap(t_stack **head)
{
	t_stack	*c;

	c = NULL;
	if (*head)
	{
		push(head, &c);
		rotate(head);
		push(&c, head);
		rrotate(head);
	}
	return (0);
}
