#include "push_swap.h"
#include <stdio.h>
#include "stack.h"
#include "../srcs/test.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = parse_argv(argc, argv);
	printf("%d\n", ft_issorted(stack));
	return (0);
}

int	push_swap(t_vars *vars, t_list **cmd, char *s)
{
	t_list	*new;

	if (push_swap_operation(vars, s) < 0)
		return (-1);
	new = ft_lstnew(s);
	if (new == NULL)
		return (-1);
	ft_lstadd_back(cmd, new);
	return (0);
}

int	push_swap_operation(t_vars *vars, char *s)
{
	if (ft_strcmp(s, "pa") == 0)
		return (pa(vars));
	else if (ft_strcmp(s, "pb") == 0)
		return (pb(vars));
	else if (ft_strcmp(s, "ra") == 0)
		return (ra(vars));
	else if (ft_strcmp(s, "rra") == 0)
		return (rra(vars));
	else if (ft_strcmp(s, "rb") == 0)
		return (rb(vars));
	else if (ft_strcmp(s, "rrb") == 0)
		return (rrb(vars));
	else if (ft_strcmp(s, "sa") == 0)
		return (sa(vars));
	else if (ft_strcmp(s, "sb") == 0)
		return (sb(vars));
	else if (ft_strcmp(s, "ss") == 0)
		return (ss(vars));
	else if (ft_strcmp(s, "rr") == 0)
		return (rr(vars));
	else if (ft_strcmp(s, "rrr") == 0)
		return (rrr(vars));
	else
		return (-1);
}

void	ft_lstswap(t_list *n1, t_list *n2)
{
	void	*temp;

	temp = n1->content;
	n1->content = n2->content;
	n2->content = temp;
}

int	ft_lstdel_pointer(t_list **lst, t_list *prev, t_list *node)
{
	if (prev == NULL)
		*lst = node->next;
	else
		prev->next = node->next;
	ft_lstdelone(node);
	return (0);
}

int	ft_lstdel(t_list **lst, t_list *node)
{
	t_list	*prev;

	prev = *lst;
	while (prev)
	{
		if (prev->next == node)
			break ;
		prev = prev->next;
	}
	ft_lstdel_pointer(lst, prev, node);
	return (0);
}
