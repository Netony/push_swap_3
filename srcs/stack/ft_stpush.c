#include "stack.h"

int	ft_stpush_data(t_stack **head, int data)
{
	t_stack	*new;

	new = ft_stnew(data);
	if (new == NULL)
		return (-1);
	return (ft_stpush_stack(head, new));
}

int	ft_stpush_stack(t_stack **head, t_stack *new)
{
	t_stack	*last;

	last = ft_stlast(new);
	if (*head)
	{
		new->prev = (*head)->prev;
		last->next = *head;
		new->prev->next = new;
		last->next->prev = last;
	}
	*head = new;
	return (0);
}

int	ft_stpush_one(t_stack **head, t_stack **from)
{
	if (*from == NULL)
		return (-1);
	return (ft_stpush_data(head, ft_stpop(from)));
}
