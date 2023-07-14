#include "push_swap.h"

int	vars_init(t_vars *vars, int argc, char **argv);

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	//greedy(&vars);
	ft_stprint(vars.a);
	return (0);
}


/*
int	test(void)
{
	t_stack	*a;
	t_stack	*b;

	a = parse_argv(argc, argv);
	if (a == NULL)
		return (NULL);
	b = NULL;
}
*/

int	vars_init(t_vars *vars, int argc, char **argv)
{
	vars->a = parse_argv(argc, argv);
	if (vars->a == NULL)
		return (-1);
	vars->b = NULL;
	vars->a_size = ft_stsize(vars->a);
	vars->b_size = 0;
	return (0);
}
