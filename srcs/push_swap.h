#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"
# include <stdio.h>

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmds;
}	t_vars;

typedef struct s_cmd
{
	char	*cmd;
	int		count;
}	t_cmd;

t_stack	*parse_argv(int argc, char **argv);

int		ft_abs(int a);
int		ft_abs_sum(int a, int b);

int		pa(t_vars *vars);
int		pb(t_vars *vars);
int		ra(t_vars *vars);
int		rra(t_vars *vars);
int		rb(t_vars *vars);
int		rrb(t_vars *vars);
int		sa(t_vars *vars);
int		sb(t_vars *vars);
int		ss(t_vars *vars);
int		rr(t_vars *vars);
int		rrr(t_vars *vars);

#endif
