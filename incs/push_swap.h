#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"
# include "greedy.h"
# include "cmd.h"
# include <stdio.h>

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmds;
}	t_vars;

t_gred	*push_swap_greedy(t_vars *vars);

t_stack	*parse_argv(int argc, char **argv);
t_cmd	*gred_to_cmd(t_gred *gred);
char	*cmd_to_char(t_list *lst);

int		gred_operation(t_vars *vars, t_gred *gred);

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
