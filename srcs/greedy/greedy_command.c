/*#include "push_swap.h"

t_list	*data_to_pa(t_data *data);
t_list	*data_to_ra(t_data *data);
t_list	*data_to_rb(t_data *data);

t_list	*data_to_cmd(t_data *data)
{
	static t_list	*(*f_list)(t_data *)[3] \
		= {data_to_rb, data_to_pa, data_to_ra};
	t_list	*cmds;
	t_list	*new;
	int		i;

	cmds = NULL;
	i = 0;
	while (i < 3)
	{
		new = f_list[i](data);
		if (new == NULL)
			ft_lstclear(&cmds);
		ft_lstadd_back(cmds, new);
		i++;
	}
	return (cmds);
}

t_list	*data_to_pa(t_data *data)
{
	t_list	*node;
	t_cmd	*cmd;

	(void)data;
	cmd = cmd_new("pa", 1);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (NULL);
}

t_list	*data_to_ra(t_data *data)
{
	t_list	*node;
	t_cmd	*cmd;

	cmd = cmd_new_negative("ra", "rra", data->ra);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (node);
}

t_list	*data_to_rb(t_data *data)
{
	t_list	*node;
	t_cmd	*cmd;

	cmd = cmd_new_negative("rb", "rrb", data->ra);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (node);
}


