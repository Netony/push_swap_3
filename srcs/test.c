#include "stack.h"
#include <stdio.h>

void	ft_stprint(t_stack *head)
{
	int	i;
	int	n;

	i = 0;
	n = ft_stsize(head);
	if (n == 0)
		printf("head: (null)\n");
	while (i < n)
	{
		printf("head[%d]: %d\n", i, head->data);
		head = head->next;
		i++;
	}
}

void	ft_sptprint(char **s)
{
	int	i;
	
	i = 0;
	while (s[i])
	{
		printf("s[%d]: %s\n", i, s[i]);
		i++;
	}
}
