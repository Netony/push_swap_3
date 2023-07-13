#include "stack.h"
#include <stdio.h>

void	ft_stprint(t_stack *head)
{
	int	i;
	int	n;

	i = 0;
	printf("TEST\n");
	printf("head: %p\n", head);
	printf("head->data: %d\n", head->data);
	printf("head->prev: %p\n", head->prev);
	printf("head->prev->data: %d\n", head->prev->data);
	n = ft_stsize(head);
	while (i < n)
	{
		printf("head[%d]: %d\n", i, head->data);
		head = head->next;
		i++;
	}
}
