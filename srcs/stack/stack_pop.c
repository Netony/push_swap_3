/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:05:53 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:07:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

void	ft_stclear(t_stack **head)
{
	while (*head)
		ft_stpop(head);
}

int	ft_stpop(t_stack **head)
{
	t_stack	*pop;
	int		data;

	pop = *head;
	if (pop)
	{
		(pop->next)->prev = pop->prev;
		(pop->prev)->next = pop->next;
		if (pop == pop->next)
			*head = NULL;
		else
			*head = (*head)->next;
		data = pop->data;
		free(pop);
	}
	else
		data = -1;
	return (data);
}
