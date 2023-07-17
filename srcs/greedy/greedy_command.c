#include "push_swap.h"

t_list	*gred_to_pa(t_gred *gred);
t_list	*gred_to_ra(t_gred *gred);
t_list	*gred_to_rb(t_gred *gred);

t_list	*gred_to_cmd(t_gred *gred)
{
	static t_list	*(*f_list)(t_gred *)[3] \
		= {gred_to_rb, gred_to_pa, gred_to_ra};
	t_list	*cmds;
	t_list	*new;
	int		i;

	cmds = NULL;
	i = 0;
	while (i < 3)
	{
		new = f_list[i](gred);
		if (new == NULL)
			ft_lstclear(&cmds);
		ft_lstadd_back(cmds, new);
		i++;
	}
	return (cmds);
}

t_list	*gred_to_pa(t_gred *gred)
{
	t_list	*node;
	t_cmd	*cmd;

	(void)gred;
	cmd = cmd_new("pa", 1);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (NULL);
}

t_list	*gred_to_ra(t_gred *gred)
{
	t_list	*node;
	t_cmd	*cmd;

	cmd = cmd_new_negative("ra", "rra", gred->ra);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (node);
}

t_list	*gred_to_rb(t_gred *gred)
{
	t_list	*node;
	t_cmd	*cmd;

	cmd = cmd_new_negative("rb", "rrb", gred->ra);
	if (cmd == NULL)
		return (NULL);
	node = ft_lstnew(cmd);
	if (node == NULL)
		cmd_del(cmd);
	return (node);
}

