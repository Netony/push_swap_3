#include <fcntl.h>
#include "lib.h"
#include "stack.h"
#include "toklen.h"
#include "push_swap.h"

t_stack	*parse_nbr(char *nptr);
t_stack	*parse_nbrs(char *nbrs_ptr);
int		ft_nptr_check(char *nptr);

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*parse;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_isin(' ', argv[i]))
			parse = parse_nbrs(argv[i]);
		else
			parse = parse_nbr(argv[i]);
		if (parse == NULL)
			return (NULL);
		ft_stpush_stack(&stack, parse);
		i++;
	}
	return (stack);
}

t_stack	*parse_nbr(char *nptr)
{
	if (ft_nptr_check(nptr) == 0)
	{
		printf("push_swap: parse error: type error");
		return (NULL);
	}
	return (ft_stnew(ft_atoi(nptr)));
}

t_stack	*parse_nbrs(char *nbrs_ptr)
{
	t_stack	*stack;
	t_stack	*new;
	char	**nptr_list;
	int		i;

	nptr_list = ft_split(nbrs_ptr, ' ');
	if (nptr_list == NULL)
		return (NULL);
	i = 0;
	stack = NULL;
	while (nptr_list[i])
	{
		new = parse_nbr(nptr_list[i++]);
		if (new == NULL)
			return (NULL);
		ft_stpush_stack(&stack, new);
	}
	return (stack);
}

int	ft_nptr_check(char *nptr)
{
	if (ft_isspace(*nptr))
		nptr += ft_duplen(nptr, " ");
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	if (ft_isin(*nptr, "0123456789"))
	{
		nptr += ft_duplen(nptr, "0123456789");
		if (*nptr)
			return (0);
	}
	else
		return (0);
	return (1);
}
