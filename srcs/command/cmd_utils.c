/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:41:24 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 11:41:25 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_iscmd(t_list *cmd, char *s)
{
	if (ft_strcmp(cmd->content, s) == 0)
		return (1);
	return (0);
}

int	ft_putcmd(char *s)
{
	int	ret;

	ret = ft_putendl_fd(s, 1);
	return (ret);
}

int	ft_putcmd_n(char *s, int n)
{
	int		put;
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (i++ < n)
	{
		put = ft_putcmd(s);
		if (put < 0)
			return (-1);
		ret += put;
	}
	return (ret);
}

t_list	*ft_lstnth(t_list *lst, int n)
{
	int	i;

	i = 0;
	while (i++ < n - 1)
		lst = lst->next;
	return (lst);
}
