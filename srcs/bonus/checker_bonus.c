/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:09:47 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 19:53:03 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "stack.h"
#include "lib.h"

static int	checker_check_vars(t_vars *vars);

int	checker_main(t_vars *vars)
{
	t_list	*cmd;
	int		ret;

	cmd = NULL;
	if (ft_get(&cmd, 0, checker_check) < 0)
		return (-1);
	if (checker(vars, cmd) < 0)
		return (-1);
	ft_lstclear(&cmd, free);
	ret = checker_check_vars(vars);
	if (ret == 0)
		ft_putendl_fd("OK", 1);
	else if (ret == 1)
		ft_putendl_fd("KO", 1);
	return (ret);
}

static int	checker_check_vars(t_vars *vars)
{
	if (ft_issorted_checker(vars->a) == 1 && vars->b == NULL)
		return (0);
	return (1);
}
