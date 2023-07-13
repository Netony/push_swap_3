/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:43:04 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/13 21:17:11 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	ps_push(t_stack **from, t_stack **to)
{
	if (*from)
	{
		if (ft_stpush(to, ft_stpop(from)) == 0)
			return (1);
	}
	return (-1);

}

int	ps_rotate(t_stack **head)
{
	if (*head)
		*head = (*head)->next;
	return (1);
}

int	ps_rrotate(t_stack **head)
{
	if (*head)
		*head = (*head)->prev;
	return (1);
}

int	ps_swap(t_stack **head)
{
	t_stack	*c;

	c = NULL;
	if (*head)
	{
		push(head, &c);
		rotate(head);
		push(&c, head);
		rotate(head);
	}
	return (1);
}
