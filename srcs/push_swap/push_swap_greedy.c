#include "lib.h"
#include "push_swap.h"
#include "../srcs/test.h"

char	**data_vars(void);
int		push_swap_data(t_vars *vars, t_data *data);

int	push_swap_greedy(t_vars *vars)
{
	int		ret;
	t_data	*data;

	ret = push_swap_move_all(vars, 3);
	if (ret < 0)
		return (-1);
	while (vars->b)
	{
		data = greedy(vars);
		ret = push_swap_data(vars, data);
		push_swap_test(vars);
		if (ret < 0)
			return (-1);
		ret = push_swap(vars, "pa");
		if (ret < 0)
			return (-1);
		free(data);
	}
	return (0);
}

int	push_swap_data(t_vars *vars, t_data *data)
{
	int		ret;
	int		i;
	char	**cmd;

	cmd = data_vars();
	ft_dataprint(data);
	i = 0;
	while (cmd[i])
	{
		ret = push_swap_n_times(vars, cmd[i], data_get(data, cmd[i]));
		if (ret < 0)
			return (-1);
		i++;
	}
	ft_sptdel(cmd);
	return (0);
}

char	**data_vars(void)
{
	char	**cmd;

	cmd = (char **)malloc(sizeof(char *) * 7);
	cmd[0] = ft_strdup("ra");
	cmd[1] = ft_strdup("rb");
	cmd[2] = ft_strdup("rra");
	cmd[3] = ft_strdup("rrb");
	cmd[4] = ft_strdup("rr");
	cmd[5] = ft_strdup("rrr");
	cmd[6] = NULL;
	return (cmd);
}

