#include "cmd.h"

t_cmd	*cmd_new(char *cmd, int count)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (new == NULL)
		return (NULL);
	new->cmd = ft_strdup(cmd);
	if (new->cmd == NULL)
	{
		free(new);
		return (NULL);
	}
	new->count = count;
	return (new);
}

t_cmd	*cmd_new_negative(char *cmd1, char *cmd2, int count)
{
	t_cmd	*cmd;

	if (count >= 0)
		cmd = cmd_new(cmd1, count);
	else
		cmd = cmd_new(cmd2, ft_abs(count));
	return (cmd);
}

void	cmd_del(t_cmd *cmd)
{
	free(cmd->cmd);
	free(cmd);
}
