#include "cmd.h"

t_list	*cmd_to_char_lst(t_cmd *cmd);

t_list	*cmd_lst_to_char_lst(t_list *cmd_lst)
{
	t_cmd	*cmd;
	t_list	*lst;
	t_list	*new;

	lst = NULL;
	while (cmd_lst)
	{
		cmd = cmd_lst->content;
		new = cmd_to_char_lst(cmd);
		if (new == NULL)
		{
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
		cmd_lst = cmd_lst->next;
	}
	return (lst);
}

t_list	*cmd_to_char_lst(t_cmd *cmd)
{
	t_list	*lst;
	t_list	*new;
	char	*dup;
	int		i;

	lst = NULL;
	i = 0;
	while (i < count)
	{
		dup = ft_strdup(cmd->cmd);
		if (dup == NULL)
			return (NULL);
		new = ft_lstnew(cmd->cmd);
		if (new == NULL)
		{
			free(dup);
			ft_lstclear(&lst, free);
			return (NULL);
		}
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}
