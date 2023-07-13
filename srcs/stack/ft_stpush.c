#include "stack.h"

int	ft_stpush(t_stack **head, int data)
{
	t_stack	*new;

	new = ft_stnew(data);
	if (new == NULL)
		return (-1);
	return (ft_stpush_stack(head, new));
}

int	ft_stpush_stack(t_stack **head, t_stack *new)
{
	if (*head)
	{
		ft_stlast(new)->next = *head;
		new->prev = (*head)->prev;
		new->prev->next = new;
		new->next->prev = new;
	}
	*head = new;
	return (0);
}
