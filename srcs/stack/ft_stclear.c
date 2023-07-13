#include "stack.h"

void	ft_stclear(t_stack **head)
{
	while (*head != NULL)
		ft_stpop(head);
}
