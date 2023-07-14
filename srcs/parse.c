#include <fcntl.h>
#include "lib.h"
#include "stack.h"
#include "toklen.h"
#include "push_swap.h"

t_stack	*parse_nbr(char *nptr);
t_stack	*parse_nbrs(char **nptrs);
int		ft_nptr_check(char *nptr);
int		ft_stack_check(t_stack *stack);

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*parse;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		if (ft_isin(' ', argv[argc - i]))
			parse = parse_nbrs(ft_split(argv[argc - i], ' '));
		else
			parse = parse_nbr(argv[argc - i]);
		if (parse == NULL)
		{
			ft_stclear(&stack);
			return (NULL);
		}
		ft_stpush_stack(&stack, parse);
		i++;
	}
	
	if (ft_stack_check(ints) < 0)
		return (NULL);
	return (stack);
}

t_stack	*parse_nbr(char *nptr)
{
	if (ft_nptr_check(nptr) == 0)
	{
		ft_putendl_fd("push_swap: invalid input", 2);
		return (NULL);
	}
	return (ft_stnew(ft_atoi(nptr)));
}

t_stack	*parse_nbrs(char **nptrs)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;
	int		n;

	stack = NULL;
	if (nptrs == NULL)
		return (NULL);
	n = ft_sptsize(nptrs);
	i = 0;
	while (i < n)
	{
		new = parse_nbr(nptrs[(n - 1) - i++]);
		if (new == NULL)
			return (NULL);
		ft_stpush_stack(&stack, new);
	}
	if (n == 0)
		ft_putendl_fd("push_swap: invalid input", 2);
	ft_sptdel(nptrs);
	return (stack);
}

