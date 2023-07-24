/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:38:05 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 19:45:49 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "toklen.h"
#include "stack.h"

int	ft_nptr_check(char *nptr)
{
	if (ft_isspace(*nptr))
		nptr += ft_duplen(nptr, " ");
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (ft_isin(*nptr, "0123456789"))
	{
		nptr += ft_duplen(nptr, "0123456789");
		if (*nptr)
			return (0);
	}
	else
		return (0);
	return (1);
}

int	ft_dup_check(t_stack *stack, int n)
{
	int		i;
	int		j;
	t_stack	*cmp;

	cmp = stack;
	if (stack == NULL)
		return (1);
	i = 0;
	while (i + 1 < n)
	{
		j = i + 1;
		cmp = stack->next;
		while (j < n)
		{
			if (stack->data == cmp->data)
				return (0);
			j++;
			cmp = cmp->next;
		}
		i++;
		stack = stack->next;
	}
	return (1);
}
