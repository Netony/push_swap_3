#include "lib.h"
#include "stack.h"
#include <stdlib.h>

int	ft_sptsize(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
		i++;
	return (i);
}

void	ft_sptdel(char **spt)
{
	int	i;

	i = 0;
	while (spt[i])
		free(spt[i++]);
	free(spt);
}

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ft_abs_sum(int a, int b)
{
	return (ft_abs(a) + ft_abs(b));
}

int	*stack_to_ints(t_stack *stack)
{
	int	i;
	int	n;
	int	*ints;

	n = ft_stsize(stack);
	ints = (int *)malloc(sizeof(int) * n);
	if (ints == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		ints[i++] = stack->data;
		stack = stack->next;
	}
	return (ints);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
