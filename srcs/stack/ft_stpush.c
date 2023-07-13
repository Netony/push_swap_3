#include "stack.h"

int	ft_stpush(t_stack **head, int data)
{
	t_stack	*new;

	new = ft_stnew(data);
	if (new == NULL)
		return (-1);
	if (*head)
	{
		new->prev = (*head)->prev;
		new->next = *head;
		(new->prev)->next = new;
		(new->next)->prev = new;
	}
	*head = new;
	return (0);
}
