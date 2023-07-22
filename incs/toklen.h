/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toklen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:37 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:13:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKLEN_H
# define TOKLEN_H

int	ft_toklen(const char *s, const char *set);
int	ft_duplen(const char *s, const char *set);
int	ft_nextlen(const char *s, const char *set);
int	ft_nextptr(const char *s, const char *set);

#endif
