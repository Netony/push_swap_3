#include "stack.h"
#include "push_swap.h"

int	push_swap(t_vars *vars)
{
	t_gred	*gred;
	t_list	*cmds;
	t_list	*node;

	cmds = NULL;
	while (vars->b)
	{
		gred = greedy(vars);
		gred_operation(vars, gred);
		node = gred_to_cmd(gred);
		free(gred);
		if (node == NULL)
		{
			ft_lstclear(cmds);
			return (-1);
		}
		ft_lstadd_back(cmds, node);
	}
	return (0);
}

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
