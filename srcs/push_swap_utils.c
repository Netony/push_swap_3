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

int	command_put(t_list *lst)
{
	while (lst)
	{
		ft_putstr_fd(lst->content, 1);
		if (lst->next)
			ft_putstr(" ", 1);
		lst = lst->next;
	}
	return (0);
}

int	command_add(t_list **lst, char *add)
{
	t_list	*new;

	new = ft_lstnew(add);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(lst, new);
	return (0);
}

t_list	*command_index(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (lst->next == NULL)
			return (NULL);
		lst = lst->next;
		i++;
	}
	return (lst);
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
