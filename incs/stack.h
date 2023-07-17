#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int		push(t_stack **from, t_stack **to);
int		rotate(t_stack **head);
int		rrotate(t_stack **head);
int		swap(t_stack **head);


t_stack	*ft_stnew(int data);
int		ft_stpush_stack(t_stack **head, t_stack *new);
int		ft_stpush_data(t_stack **head, int data);
int		ft_stpop(t_stack **head);
void	ft_stclear(t_stack **head);

int		ft_stsize(t_stack *head);
t_stack	*ft_stlast(t_stack *head);

#endif

/*
int		ft_stidx(t_stack *stack, int value);
t_stack	*ft_stdata(t_stack *head, int n);
*/
