#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parse_argv(argc, argv);
}

t_stack	*parse_argv(int argc, char **argv)
{
	t_stack	*ret;
	t_stack	*parse;
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_isin(' ', argv[i]))
			parse = parse_split(argv[i]);
		else
			parse = ft_stacknew(ft_atoi(argv[i]));
		ft_push_stack(ret, parse);
		i++;
	}
	return (ret);
}

t_stack	*parse_atoi(char *nptr)
{
	t_stack	*stack;
	int		nbr;

	nbr = ft_atoi(nptr);
	stack = ft_stackinit(nbr);
	return (stack);
}

t_stack	*parse_split(char *nbrs)
{
	t_stack	*stack;
	char	**split;
	int		i;

	split = ft_split(nbrs, ' ');
	if (split == NULL)
		return (NULL);
	i = 0;
	while (split[i])
	{
		stack_add(ft_atoi(split[i]));
		i++;
	}
	return (stack);
}
