#include "push_swap.h"
#include <stdlib.h>

t_cmd	*cmd_new(char *cmd, int count)
{
	t_cmd	*new;
	char	*dup;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->cmd = ft_strdup(cmd);
	if (new->cmd == NULL)
	{
		free(new);
		return (NULL);
	}
	cmd->count = count;
	return (new);
}

t_cmd	*cmd_new_negative(char *cmd1, char *cmd2, int count)
{
	t_cmd	*cmd;
	if (count >= 0)
		cmd = cmd_new(cmd1, gred->ra);
	else if (count < 0)
		cmd = cmd_new(cmd2, ft_abs(gred->ra));
	return (cmd);
}

t_cmd	*cmd_del(t_cmd *cmd)
{
	free(cmd->cmd);
	free(cmd);
}
