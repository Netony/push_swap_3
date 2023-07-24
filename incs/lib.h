/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:08 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:38:19 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "../libft/incs/libft.h"
# include "toklen.h"
# include "stack.h"

int		ft_strcmp(char *s1, char *s2);

int		ft_abs(int a);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

int		ft_sptsize(char **spt);
void	ft_sptdel(char **spt);

int		ft_arrsort(int *array, int size);
int		*stack_to_array(t_stack *stack);

#endif
