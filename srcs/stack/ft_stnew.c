#include "stack.h"
#include <stdlib.h>

t_stack	*ft_stnew(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new)
	{
		new->data = data;
		new->prev = new;
		new->next = new;
	}
	return (new);
}
