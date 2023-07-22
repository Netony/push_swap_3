/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:41:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 12:09:22 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "stack.h"
#include "lib.h"

int			pa(t_vars *vars);
int			pb(t_vars *vars);
int			ra(t_vars *vars);
int			rra(t_vars *vars);
int			rb(t_vars *vars);
int			rrb(t_vars *vars);
int			sa(t_vars *vars);
int			sb(t_vars *vars);
int			ss(t_vars *vars);
int			rr(t_vars *vars);
int			rrr(t_vars *vars);
static int	checker_operation(t_vars *vars, char *s);

int	checker(t_vars *vars)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(0);
		if (line)
		{
			ret = checker_operation(vars, line);
			free(line);
			if (ret == -2)
				return (-1);
		}
		else
			break ;
	}
	if (ft_issorted_checker(vars->a) == 1 && vars->b == NULL)
		return (0);
	return (1);
}

static int	checker_operation(t_vars *vars, char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		return (pa(vars));
	else if (ft_strcmp(s, "pb\n") == 0)
		return (pb(vars));
	else if (ft_strcmp(s, "ra\n") == 0)
		return (ra(vars));
	else if (ft_strcmp(s, "rra\n") == 0)
		return (rra(vars));
	else if (ft_strcmp(s, "rb\n") == 0)
		return (rb(vars));
	else if (ft_strcmp(s, "rrb\n") == 0)
		return (rrb(vars));
	else if (ft_strcmp(s, "sa\n") == 0)
		return (sa(vars));
	else if (ft_strcmp(s, "sb\n") == 0)
		return (sb(vars));
	else if (ft_strcmp(s, "ss\n") == 0)
		return (ss(vars));
	else if (ft_strcmp(s, "rr\n") == 0)
		return (rr(vars));
	else if (ft_strcmp(s, "rrr\n") == 0)
		return (rrr(vars));
	else
		return (-2);
}
