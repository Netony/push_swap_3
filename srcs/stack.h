#include <stdlib.h>

typedef struct	s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stnew(int data);
int		ft_stpush(t_stack **head, int data);
int		ft_stpop(t_stack **head);

int		ft_stsize(t_stack *head);
t_stack	*ft_stlast(t_stack *head);
t_stack	*ft_stdata(t_stack *head, int n);
void	ft_stclear(t_stack **head);
