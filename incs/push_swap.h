#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"
# include "data.h"
# include <stdio.h>

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmd;
}	t_vars;

t_stack	*parse_argv(int argc, char **argv);
t_data	*greedy(t_vars *vars);

int		push_swap_main(t_vars *vars);

int		push_swap_move_all(t_vars *vars, int n);
int		push_swap_sort(t_vars *vars, char *a);
int		push_swap_greedy(t_vars *vars);

int		push_swap_circular(t_vars *vars, int index);

int		push_swap_min_rotate(t_vars *vars, char *ra, char *rra, int index);
int		push_swap(t_vars *vars, char *s);
int		push_swap_n_times(t_vars *vars, char *s, int n);


#endif
