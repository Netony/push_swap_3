#include "push_swap.h"

int	vars_init(t_vars *vars, int argc, char **argv);
int	ft_stprint(t_stack *stack);

int	main(int argc, char **argv)
{
	t_vars	vars;
	if (vars_init(&vars, argc, argv) < 0)
		return (-1);
	//greedy_main(&vars);
	ft_stprint(vars.a);
	return (0);
}

/*
int	main(int argc, char **argv)
int	main(void)
{
}
*/

int	vars_init(t_vars *vars, int argc, char **argv)
{
	vars->a = parse_argv(argc, argv);
	if (vars->a == NULL)
		return (-1);
	vars->b = NULL;
	return (0);
}
