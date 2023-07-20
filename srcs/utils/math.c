/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 20:29:38 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/20 20:29:38 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int a)
{
	if (a < 0)
		a = -a;
	return (a);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
