/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:38:05 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 16:42:32 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "toklen.h"
#include "stack.h"

int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);
int		*stack_to_ints(t_stack *stack);
int		ints_check_dup(int *ints, int n);

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

int	ft_stack_check(t_stack *stack)
{
	int	*ints;
	int	size;
	int	ret;

	ints = stack_to_ints(stack);
	size = ft_stsize(stack);
	if (ints == NULL)
		return (-1);
	ret = ints_check_dup(ints, size);
	free(ints);
	return (ret);
}

int	ints_check_dup(int *ints, int n)
{
	int	i;
	int	j;

	i = 0;
	if (ints == NULL)
		return (0);
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ints[i] == ints[j])
			{
				ft_putendl_fd("Error", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
