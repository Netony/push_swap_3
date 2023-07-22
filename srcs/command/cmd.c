/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:41:23 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 12:37:16 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int		ft_iscmd(t_list *cmd, char *s);
int		ft_putcmd(char *s);
int		ft_putcmd_n(char *s, int n);
t_list	*ft_lstnth(t_list *lst, int n);

int		cmd_pa_pb(t_list **cmd);

int	cmd_put(t_list *cmd)
{
	int	ret;
	int	put;

	ret = 0;
	while (cmd)
	{
		if (ft_iscmd(cmd, "pa") || ft_iscmd(cmd, "pb"))
			put = cmd_pa_pb(&cmd);
		else
			put = ft_putcmd(cmd->content);
		if (put < 0)
			return (-1);
		ret += put;
		cmd = cmd->next;
	}
	return (ret);
}

int	cmd_pa_pb(t_list **cmd)
{
	int		pa;
	int		pb;
	int		ret;
	t_list	*cur;

	cur = *cmd;
	pa = 0;
	pb = 0;
	ret = 0;
	while (cur)
	{
		if (ft_iscmd(cur, "pa"))
			pa++;
		else if (ft_iscmd(cur, "pb"))
			pb++;
		else
			break ;
		cur = cur->next;
	}
	*cmd = ft_lstnth(*cmd, pa + pb);
	if (pa > pb)
		ret += ft_putcmd_n("pa", pa - pb);
	else
		ret += ft_putcmd_n("pb", pb - pa);
	return (ret);
}
