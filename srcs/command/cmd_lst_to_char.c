#include "cmd.h"

void	cltc_cat(char *dst, char *src, int n);
int		cltc_size(t_list *lst);

char	*cmd_lst_to_char(t_list *cmd_lst)
{
	size_t	size;
	t_cmd	*cmd;
	char	*ret;

	size = cltc_size(cmd_lst);
	if (size == 1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		cltc_cat(ret, cmd->cmd, cmd->count);
		cmd_lst = cmd_lst->next;
	}
	return (ret);
}

void	cltc_cat(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_strlcat(dst, src, ft_strlen(src));
		ft_strlcat(dst, " ", 1);
		i++;
	}
}

int	cltc_size(t_list *lst)
{
	size_t	size;
	t_cmd	*cmd;

	size = 1;
	while (lst)
	{
		cmd = lst->content;
		size += (1 + ft_strlen(cmd->cmd)) * cmd->count;
		lst = lst->next;
	}
	return (size);
}
