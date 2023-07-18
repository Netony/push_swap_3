#ifndef GREEDY_H
# define GREEDY_H

#include "push_swap.h"
#include "data.h"

int		greedy_count_ra(t_vars *vars, int value);
int		greedy_count_rb(t_vars *vars, int index);
t_data	*greedy_init(t_vars *vars);
void	greedy_get_data(t_data *gred, t_vars *vars, int index, int value);
t_data	*greedy(t_vars *vars);


#endif
