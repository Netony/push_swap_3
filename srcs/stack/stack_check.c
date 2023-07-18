#include "stack.h"

int	ft_issorted(t_stack *stack)
{
	int	sort;
	int	i;
	int	size;

	size = ft_stsize(stack);
	i = 0;
	sort = 0;
	while (i < size)
	{
		if (stack->data > stack->next->data)
			sort++;
		i++;
		stack = stack->next;
	}
	return (sort);
}
