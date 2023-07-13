#include "stack.h"

int	ft_stpop(t_stack **head)
{
	t_stack	*pop;
	int		data;

	pop = *head;
	if (pop)
	{
		(pop->next)->prev = pop->prev;
		(pop->prev)->next = pop->next;
		if (cur == cur->next)
			*head = NULL;
		else
			*head = (*head)->next;
		data = pop->data;
		free(pop);
	}
	else
		data = -1;
	return (data);
}
