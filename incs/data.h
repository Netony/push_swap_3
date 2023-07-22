/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 13:13:06 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 13:17:23 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_data
{
	int	min;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
}	t_data;

int		ft_min_4(int a, int b, int c, int d);
void	data_bzero(t_data *data);
t_data	*data_new(void);

int		data_get(t_data *data, char *s);

#endif
