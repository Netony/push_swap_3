/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:09 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:13:33 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "lib.h"
# include "stack.h"
# include "data.h"

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	t_list	*cmd;
}	t_vars;

t_stack	*parse_argv(int argc, char **argv);

int		cmd_put(t_list *cmd);

int		push_swap_main(t_vars *vars);

int		push_swap_push_all(t_vars *vars, char *pa, int n);
int		push_swap_sort(t_vars *vars, char *a);
int		push_swap_three(t_vars *vars, char *a);
int		push_swap_greedy(t_vars *vars);

int		push_swap_data(t_vars *vars, t_data *data);
int		push_swap_rotate(t_vars *vars, char *ra, char *rra, int index);

int		push_swap(t_vars *vars, char *s);
int		push_swap_n(t_vars *vars, char *s, int n);

#endif
