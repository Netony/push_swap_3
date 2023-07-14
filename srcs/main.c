#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack *a;

	i = 1;
	a = parse_argv(argc, argv);
	ft_stprint(a);
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
