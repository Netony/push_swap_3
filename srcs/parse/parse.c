#include <fcntl.h>
#include "lib.h"
#include "stack.h"
#include "push_swap.h"

t_stack	*parse_nbr(char *nptr);
t_stack	*parse_nbr_space(char **nptrs);
int		ft_nptr_check(char *nptr);
int		ft_stack_check(t_stack *stack);
int		ft_integer_check(int atoi, char *nptr);
int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*parse;
	int		i;

	i = 1;
	stack = NULL;
	while (i < argc)
	{
		parse = parse_nbr(argv[argc - i]);
		if (parse == NULL)
		{
			ft_stclear(&stack);
			return (NULL);
		}
		ft_stpush_stack(&stack, parse);
		i++;
	}
	if (ft_stack_check(stack) == 0)
	{
		ft_stclear(&stack);
		return (NULL);
	}
	return (stack);
}

t_stack	*parse_nbr(char *nptr)
{
	t_stack	*parse;
	int		atoi;

	if (ft_isin(' ', nptr))
		parse = parse_nbr_space(ft_split(nptr, ' '));
	else
	{
		if (ft_nptr_check(nptr) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		atoi = ft_atoi(nptr);
		if (ft_integer_check(atoi, nptr) == 0)
		{
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		parse = ft_stnew(atoi);
	}
	return (parse);
}

t_stack	*parse_nbr_space(char **nptrs)
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
		ft_putendl_fd("Error", 2);
	ft_sptdel(nptrs);
	return (stack);
}

