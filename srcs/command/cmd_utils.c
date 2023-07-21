#include "lib.h"
t_list	*ft_lstnth(t_list *lst, int n);

int	ft_iscmd(t_list *cmd, char *s)
{
	if (ft_strcmp(cmd->content, s) == 0)
		return (1);
	return (0);
}

int	ft_putcmd(char *s, t_list *cmd)
{
	int	put;
	int	ret;

	ret = 0;
	put = ft_putstr_fd(s, 1);
	if (put < 0)
		return (-1);
	ret += put;
	if (cmd->next)
		put = ft_putchar_fd('\n', 1);
	else
		put = ft_putchar_fd('\n', 1);
	if (put < 0)
		return (-1);
	return (ret);
}

int	ft_putcmd_replace(t_list **replace, int rep, char *new, int n)
{
	t_list	*last;
	int		put;
	int		ret;
	int		i;

	last = ft_lstnth(*replace, rep);
	ret = 0;
	i = 0;
	while (i++ < n)
	{
		if (i == n)
			put = ft_putcmd(new, last);
		else
			put = ft_putcmd(new, *replace);
		if (put < 0)
			return (-1);
		ret += put;
	}
	*replace = last;
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
