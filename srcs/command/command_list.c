#include "cmd.h"

t_list	*cmd_lstnew_negative(char *cmd1, char *cmd2, int count)
{
	t_cmd	*cmd;
	t_list	*cmd_node;

	cmd = cmd_new_negative(cmd1, cmd2, count);
	if (cmd == NULL)
		return (NULL);
	cmd_node = ft_lstnew(cmd);
	return (cmd_node);
}

t_list	*cmd_lstnew(char *cmd1, int count)
{
	t_cmd	*cmd;
	t_list	*cmd_node;

	cmd = cmd_new(cmd1, count);
	if (cmd == NULL)
		return (NULL);
	cmd_node = ft_lstnew(cmd);
	return (cmd_node);
}

void	cmd_lstclear(t_list **cmd_lst)
{
	ft_lstclear(cmd_lst, (void (*)(void *))cmd_del);
}

t_list	*data_to_cmd_list(t_data *data)
{
	t_list	*cmd_node;
	t_list	*cmd_lst;
	int		i;
	
	cmd_lst = NULL;
	i = 0;
	while (i < 3)
	{
		if (i == 0)
			cmd_node = cmd_lstnew_negative("rb", "rrb", data->rb);
		else if (i == 1)
			cmd_node = cmd_lstnew("pa", 1);
		else if (i == 2)
			cmd_node = cmd_lstnew_negative("ra", "rra", data->ra);
		if (cmd_node == NULL)
		{
			cmd_lstclear(&cmd_lst);
			return (NULL);
		}
		ft_lstadd_back(&cmd_lst, cmd_node);
		i++;
	}
	return (cmd_lst);
}

t_list	*char_to_cmd_list(char *cmd)
{
	return (cmd_lstnew(cmd, 1));
}
