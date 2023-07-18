#include "push_swap.h"
#include <stdio.h>
#include "stack.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parse_argv(argc, argv);

	printf("%d\n", ft_issorted(stack));
	return (0);
}

