#include "stack.h"

t_stack	*ft_stlast(t_stack *head)
{
	return (head->prev);
}

int	ft_stsize(t_stack *head)
{
	int		size;
	t_stack	*last;

	if (head == NULL)
		return (0);
	size = 1;
	last = ft_stlast(head);
	while (last != head)
	{
		last = last->prev;
		size++;
	}
	return (size);
}

int	ft_stmin(t_stack *stack)
{
	int	i;
	int	size;
	int	min;
	int	index;

	i = 0;
	index = 0;
	size = ft_stsize(stack);
	if (stack)
		min = stack->data;
	while (i < size)
	{
		if (stack->data < min)
		{
			min = stack->data;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (index);
}

int	ft_stidx_near(t_stack *stack, int value)
{
	int	index;
	int	i;
	int	size;
	int	min;

	size = ft_stsize(stack);
	index = 0;
	min = INT_MAX;
	i = 0;
	while (i < size)
	{
		if (stack->data > value)
		{
			if (stack->data < min)
			{
				min = stack->data;
				index = i;
			}
		}
		stack = stack->next;
		i++;
	}
	if (min == INT_MAX)
		index = ft_stmin(stack);
	return (index);
}

