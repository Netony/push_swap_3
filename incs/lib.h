/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:15:02 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/incs/libft.h"
# include "toklen.h"

int		ft_strcmp(char *s1, char *s2);

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);

#endif
