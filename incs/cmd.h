#ifndef CMD_H
# define CMD_H

#include "lib.h"
#include "data.h"

typedef struct s_cmd
{
	char	*cmd;
	int		count;
}	t_cmd;

t_cmd	*cmd_new(char *cmd, int count);
t_cmd	*cmd_new_negative(char *cmd1, char *cmd2, int count);
void	cmd_del(t_cmd *cmd);

t_list	*cmd_lstnew_negative(char *cmd1, char *cmd2, int count);
t_list	*cmd_lstnew(char *cmd1, int count);
void	cmd_lstclear(t_list **cmd_lst);

t_list	*data_to_cmd_list(t_data *data);
t_list	*char_to_cmd_list(char *cmd);
char	*cmd_lst_to_char(t_list *cmd_lst);

#endif
