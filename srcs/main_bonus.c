/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:45:41 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 16:16:50 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	vars_init(t_vars *vars, int argc, char **argv);
int	vars_end(t_vars *vars);

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		ret;

	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	ret = checker_main(&vars);
	vars_end(&vars);
	if (ret < 0)
	{
		ft_putendl_fd("Error", 2);
		return (-1);
	}
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
