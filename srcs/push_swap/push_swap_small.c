/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 12:26:16 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 12:26:17 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"
#include "push_swap.h"

static char	**data_vars(void);

int	push_swap_rotate(t_vars *vars, char *ra, char *rra, int index)
{
	int	size;
	int	ret;

	size = ft_stsize(vars->a);
	if (index < size - index)
		ret = push_swap_n(vars, ra, index);
	else
		ret = push_swap_n(vars, rra, size - index);
	if (ret < 0)
		return (-1);
	return (0);
}

int	push_swap_data(t_vars *vars, t_data *data)
{
	int		ret;
	int		i;
	char	**cmd;

	cmd = data_vars();
	i = 0;
	while (cmd[i])
	{
		ret = push_swap_n(vars, cmd[i], data_get(data, cmd[i]));
		if (ret < 0)
			return (-1);
		i++;
	}
	ft_sptdel(cmd);
	return (0);
}

static char	**data_vars(void)
{
	char	**cmd;

	cmd = (char **)malloc(sizeof(char *) * 7);
	cmd[0] = ft_strdup("ra");
	cmd[1] = ft_strdup("rb");
	cmd[2] = ft_strdup("rra");
	cmd[3] = ft_strdup("rrb");
	cmd[4] = ft_strdup("rr");
	cmd[5] = ft_strdup("rrr");
	cmd[6] = NULL;
	return (cmd);
}
