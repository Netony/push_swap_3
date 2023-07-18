#include "data.h"
#include "greedy.h"
#include "stack.h"
#include "push_swap.h"

t_list	*ps_move_all(t_vars *vars);
t_list	*ps_greedy(t_vars *vars);
t_list	*ps_last_rotate(t_vars *vars);

char	*push_swap(t_vars *vars)
{
	t_list	*(*functions[3])(t_vars *)
		= {ps_move_all, ps_greedy, ps_last_rotate};
	t_list	*cmd_lst;
	t_list	*cmd_new;
	char	*ret;
	int		i;

	i = 0;
	cmd_lst = NULL;
	while (i < 3)
	{
		cmd_new = functions[i](vars);
		if (cmd_new == NULL)
		{
			cmd_lstclear(&cmd_lst);
			return (NULL);
		}
		ft_lstadd_back(&cmd_lst, cmd_new);
		i++;
	}
	ret = cmd_lst_to_char(cmd_lst);
	cmd_lstclear(&cmd_lst);
	return (ret);
}
t_list	*ps_move_all(t_vars *vars)
{
	int	i;
	int	size;

	i = 0;
	size = ft_stsize(vars->a);
	while (i < size)
	{
		push_swap_pb(vars);
		i++;
	}
	return (cmd_lstnew("pb", i));
}

t_list	*ps_greedy(t_vars *vars)
{
	t_data	*data;
	t_list	*cmd_lst;
	t_list	*cmd_new;

	cmd_lst = NULL;
	while (vars->b)
	{
		data = greedy(vars);
		data_operation(vars, data);
		push_swap_pa(vars);
		cmd_new = data_to_cmd_list(data);
		free(data);
		if (cmd_new == NULL)
		{
			cmd_lstclear(&cmd_lst);
			return (NULL);
		}
		ft_lstadd_back(&cmd_lst, cmd_new);
	}
	return (cmd_lst);
}

t_list	*ps_last_rotate(t_vars *vars)
{
	t_data	*data;
	t_list	*cmd_lst;
	int		ra;
	int		size;

	ra = ft_stmin(vars->a);
	size = ft_stsize(vars->a);
	ra = greedy_get_data_rotate(ra, size);
	data = data_new(ra, 0);
	if (data == NULL)
		return (NULL);
	data_operation(vars, data);
	cmd_lst = data_to_cmd_list(data);
	free(data);
	return (cmd_lst);
}
