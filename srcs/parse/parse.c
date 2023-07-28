/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:37:53 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/28 20:01:37 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "lib.h"
#include "stack.h"
#include "push_swap.h"

t_stack	*parse_nbr(char *nptr);
t_stack	*parse_nbr_space(char **nptrs);
int		ft_nptr_check(char *nptr);
int		ft_dup_check(t_stack *stack, int n);
int		ft_integer_check(char *nptr);
int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*parse;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		parse = parse_nbr(argv[argc - i++]);
		if (parse == NULL)
		{
			ft_stclear(&stack);
			return (NULL);
		}
		ft_stpush_stack(&stack, parse);
	}
	if (ft_dup_check(stack, ft_stsize(stack)) == 0)
	{
		ft_putendl_fd("Error", 2);
		ft_stclear(&stack);
		return (NULL);
	}
	return (stack);
}

t_stack	*parse_nbr(char *nptr)
{
	t_stack	*parse;
	int		atoi;

	if (ft_isin(' ', nptr))
		parse = parse_nbr_space(ft_split(nptr, ' '));
	else
	{
		if (ft_nptr_check(nptr) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		if (ft_integer_check(nptr) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		atoi = ft_atoi(nptr);
		parse = ft_stnew(atoi);
	}
	return (parse);
}

t_stack	*parse_nbr_space(char **nptrs)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;
	int		n;

	stack = NULL;
	if (nptrs == NULL)
		return (NULL);
	n = ft_sptsize(nptrs);
	i = 0;
	while (i < n)
	{
		new = parse_nbr(nptrs[(n - 1) - i++]);
		if (new == NULL)
		{
			ft_stclear(&stack);
			break ;
		}
		ft_stpush_stack(&stack, new);
	}
	ft_sptdel(nptrs);
	return (stack);
}
