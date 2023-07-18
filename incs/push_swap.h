#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"
# include "cmd.h"
# include <stdio.h>

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmds;
}	t_vars;

t_stack	*parse_argv(int argc, char **argv);
char	*cmd_to_char(t_list *lst);

char	*push_swap(t_vars *vars);
int		data_operation(t_vars *vars, t_data *data);

int		push_swap_pa(t_vars *vars);
int		push_swap_pb(t_vars *vars);
int		push_swap_ra(t_vars *vars);
int		push_swap_rra(t_vars *vars);
int		push_swap_rb(t_vars *vars);
int		push_swap_rrb(t_vars *vars);
int		push_swap_sa(t_vars *vars);
int		push_swap_sb(t_vars *vars);
int		push_swap_ss(t_vars *vars);
int		push_swap_rr(t_vars *vars);
int		push_swap_rrr(t_vars *vars);


#endif
/*
int		ft_stprint(t_stack *stack);
int		push_swap_test(t_vars *vars);
int		ft_cmd_lst_print(t_list *lst);
*/
