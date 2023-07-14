#include "lib.h"
#include "stack.h"

int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);
int		*stack_to_ints(t_stack *stack);

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

int	ft_stack_check(t_stack *stack)
{
	int	*ints;
	int	size;
	int	ret;

	ints = stack_to_ints(stack);
	size = ft_stsize(stack);
	if (ints == NULL)
		return (-1);
	ret = ft_ints_check(ints, size);
	free(ints);
	return (ret);
}

int	ft_ints_check(int *ints, int n)
{
	int	i;
	int	j;

	i = 0;
	ints = stack_to_ints(stack);
	if (ints == NULL)
		return (-1);
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (ints[i] == ints[j])
			{
				ft_putendl_fd("push_swap: invalid input: duplicated", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
