#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

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
int		ft_stmin(t_stack *stack);
int		ft_stidx_near(t_stack *stack, int value);
int		ft_issorted(t_stack *stack);
int		ft_issorted_checker(t_stack *stack);

int		ft_stmin_index(t_stack *stack);
int		ft_stmax_index(t_stack *stack);
int		ft_stmid_index(t_stack *stack);

#endif
