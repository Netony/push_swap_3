#include "push_swap.h"
#include "../srcs/test.h"

int	ft_putcmd(t_list *cmd);
int	vars_init(t_vars *vars, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		ret;

	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	push_swap_test(&vars);
	ret = push_swap_main(&vars);
	ft_putcmd(vars.cmd);
	push_swap_test(&vars);
	return (0);
}

int	vars_init(t_vars *vars, int argc, char **argv)
{
	vars->a = parse_argv(argc, argv);
	if (vars->a == NULL)
		return (-1);
	vars->b = NULL;
	return (0);
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

int	ft_putcmd(t_list *cmd)
{
	int	ret;
	int	put;

	ret = 0;
	while (cmd)
	{
		put = ft_putstr_fd(cmd->content, 1);
		if (put < 0)
			return (-1);
		ret += put;
		if (cmd->next)
			put = ft_putchar_fd(' ', 1);
		else
			put = ft_putchar_fd('\n', 1);
		if (put < 0)
			return (-1);
		ret += put;
		cmd = cmd->next;
	}
	return (ret);
}
