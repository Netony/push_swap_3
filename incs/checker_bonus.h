/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:03 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 16:07:27 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include "push_swap.h"

int	checker_main(t_vars *vars);

int	checker(t_vars *vars, t_list *cmd);
int	checker_check_vars(t_vars *vars);
int	checker_check(char *s);

int	ft_get(t_list **lst, int fd, int (*check)(char *s));

#endif
