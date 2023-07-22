/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:39 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 12:17:21 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	vars_init(t_vars *vars, int argc, char **argv);
int	vars_end(t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	if (push_swap_main(&vars) < 0)
	{
		vars_end(&vars);
		ft_putendl_fd("Error", 2);
		return (-1);
	}
	if (cmd_put(vars.cmd) < 0)
	{
		ft_putendl_fd("Error", 2);
		vars_end(&vars);
		return (-1);
	}
	vars_end(&vars);
	return (0);
}

int	vars_init(t_vars *vars, int argc, char **argv)
{
	vars->a = parse_argv(argc, argv);
	if (vars->a == NULL)
		return (-1);
	vars->b = NULL;
	return (0);
}

int	vars_end(t_vars *vars)
{
	ft_lstclear(&(vars->cmd), free);
	ft_stclear(&(vars->a));
	ft_stclear(&(vars->b));
	return (0);
}
