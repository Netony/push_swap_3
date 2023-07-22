/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:12:29 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 16:12:30 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

int	ft_get(t_list **lst, int fd, int (*check)(char *s))
{
	char	*buf;
	t_list	*node;

	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		if (check(buf) == 0)
		{
			free(buf);
			ft_lstclear(lst, free);
			return (-1);
		}
		node = ft_lstnew(buf);
		if (node == NULL)
		{
			free(buf);
			ft_lstclear(lst, free);
			return (-1);
		}
		ft_lstadd_back(lst, node);
	}
	return (0);
}

int	checker_check(char *s)
{
	if (ft_strcmp(s, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(s, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(s, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(s, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(s, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(s, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(s, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(s, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(s, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(s, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(s, "rrr\n") == 0)
		return (1);
	else
		return (0);
}
