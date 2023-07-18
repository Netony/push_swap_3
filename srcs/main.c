#include "push_swap.h"

int	vars_init(t_vars *vars, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_vars	vars;
	char	*ret;

	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	ret = push_swap(&vars);
	free(ret);
	ft_putendl_fd(ret, 1);
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

