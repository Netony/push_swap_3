#include <stdio.h>
#include "stack.h"

int	ft_stprint(t_stack *stack)
{
	int	i;
	int	n;

	n = ft_stsize(stack);
	i = 0;
	while (i < n)
	{
		printf("stack[%d]: %d\n", i, stack->data);
		i++;
		stack = stack->next;
	}
	return (0);
}
