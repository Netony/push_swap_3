#include "data.h"
#include "greedy.h"
#include "stack.h"
#include "push_swap.h"

t_list	*push_swap_move_all(t_vars *vars);
t_list	*push_swap_greedy(t_vars *vars);

char	*push_swap(t_vars *vars)
{
	t_list	*cmd_lst;
	t_list	*cmd_new;
	char	*ret;
	int		i;

	i = 0;
	cmd_lst = NULL;
	while (i < 2)
	{
		if (i == 0)
			cmd_new = push_swap_move_all(vars);
		else if (i == 1)
			cmd_new = push_swap_greedy(vars);
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

/*
int	ft_get_pivot(t_stack *stack)
{
	int	min;
	int	max;

	min = stack->data;
	max = stack->data;
	while (stack)
	{
		if (stack->data > max)
			max = stack->data;
		else if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return ((max + min) / 2);
}
*/

t_list	*push_swap_move_all(t_vars *vars)
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

t_list	*push_swap_greedy(t_vars *vars)
{
	t_data	*data;
	t_list	*cmd_lst;
	t_list	*cmd_new;

	cmd_lst = NULL;
	while (vars->b)
	{
		push_swap_test(vars);
		data = greedy(vars);
		data_operation(vars, data);
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
