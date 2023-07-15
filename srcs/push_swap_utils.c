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

int	get_rotate_count(int rotate, int max_index)
{
	if (rotate > (max_index + 1) / 2)
		rotate -= max_index;
	return (rotate);
}
