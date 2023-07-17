#include "greedy.h"

t_gred	*push_swap_greedy(t_vars *vars)
{
	t_stack	*b;
	t_gred	*gred;
	int		n;
	int		i;

	gred = (t_gred *)malloc(sizeof(t_gred));
	b = vars->b;
	n = ft_stsize(b);
	i = 0;
	while (i < n)
	{
		greedy_check_n_update(vars, &gred, i, b->data);
		i++;
		b = b->next;
	}
	gred_operation(vars, gred);
	return (gred);
}
