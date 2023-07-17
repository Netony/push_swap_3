#ifndef CMD_H
# define CMD_H

#include <stdlib.h>

typedef struct s_cmd
{
	char	*cmd;
	int		count;
}	t_cmd;

t_cmd	*cmd_new(char *cmd, int count);
t_cmd	*cmd_new_negative(char *cmd1, char *cmd2, int count);
void	cmd_del(t_cmd *cmd);

#endif
