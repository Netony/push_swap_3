#include "lib.h"

int	ft_iscmd(t_list *cmd, char *s);
int	ft_putcmd(char *s, t_list *cmd);
int	ft_putcmd_replace(t_list **replace, int rep, char *new, int n);
int	cmd_pa_pb(t_list **cmd);

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
			put = ft_putcmd(cmd->content, cmd);
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
			break;
		cur = cur->next;
	}
	if (pa > pb)
		ret += ft_putcmd_replace(cmd, pa + pb, "pa", pa - pb);
	else if (pb > pa)
		ret += ft_putcmd_replace(cmd, pa + pb, "pb", pb - pa);
	return (ret);
}
