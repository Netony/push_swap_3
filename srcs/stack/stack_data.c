#include "stack.h"

t_stack	*ft_stlast(t_stack *head)
{
	return (head->prev);
}

t_stack	*ft_stdata(t_stack *head, int n)
{
	int	i;

	i = 0;
	while (i++ < n)
		head = head->next;
	return (head);
}

int	ft_stsize(t_stack *head)
{
	int		size;
	t_stack	*last;

	size = 1;
	last = ft_stlast(head);
	while (head != last)
	{
		head = head->next;
		size++;
	}
	return (size);
}
