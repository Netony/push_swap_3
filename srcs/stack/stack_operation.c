#include "stack.h"

int	ps_push(t_stack **from, t_stack **to)
{
	return (ft_stpush_one(to, from));
}

int	ps_rotate(t_stack **head)
{
	if (*head)
		*head = (*head)->next;
	return (0);
}

int	ps_rrotate(t_stack **head)
{
	if (*head)
		*head = (*head)->prev;
	return (0);
}

int	ps_swap(t_stack **head)
{
	t_stack	*c;

	c = NULL;
	if (*head)
	{
		push(head, &c);
		rotate(head);
		push(&c, head);
		rotate(head);
	}
	return (0);
}
