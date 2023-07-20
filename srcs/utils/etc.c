#include "stack.h"

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
