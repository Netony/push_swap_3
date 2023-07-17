#include "lib.h"
#include "cmd.h"

void	cmd_to_char_cat(char *dst, char *src, int n);
int		cmd_to_char_size(t_list	*lst):

char	*cmd_to_char(t_list *lst)
{
	size_t	size;
	t_cmd	*cmd;
	char	*ret;
	int		i;

	size = cmd_to_char_size(lst);
	if (size == 1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (ret == NULL)
		return (NULL);
	while (lst)
	{
		cmd = lst->content;
		cmd_to_char_cat(ret, cmd->cmd, cmd->count);
		lst = lst->next;
	}
	return (ret);
}

void	cmd_to_char_cat(char *dst, char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_strlcat(dst, src, ft_strlen(src));
		i++;
	}
}

int	cmd_to_char_size(t_list	*lst)
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
