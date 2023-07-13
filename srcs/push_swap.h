#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"

int	ps_push(t_stack **from, t_stack **to);
int	ps_rotate(t_stack **head);
int	ps_rrotate(t_stack **head);
int	ps_swap(t_stack **head);

int	set_v1(t_stack *a, t_stack *b)
int	set_v2(t_stack *a, t_stack *b)
int	set_v3(t_stack *a, t_stack *b)
int	get_v1(t_stack *a, t_stack *b)
int	get_v2(t_stack *a, t_stack *b)
int	get_v3(t_stack *a, t_stack *b)

#endif
