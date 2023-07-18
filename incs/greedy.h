#ifndef GREEDY_H
# define GREEDY_H

#include "push_swap.h"
#include "data.h"

t_data	*greedy_init(t_vars *vars);
t_data	*greedy(t_vars *vars);

void	greedy_get_data(t_data *gred, t_vars *vars, int index, int value);
int		greedy_get_data_rotate(int rotate, int size);


#endif
