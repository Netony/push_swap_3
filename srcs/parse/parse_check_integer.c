/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:39:33 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/22 17:38:33 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_new(int nbr, int new);
static int	ft_ctoi(int c, int sign);

int	ft_integer_check(char *nptr)
{
	int	sign;
	int	nbr;
	int	new;

	sign = 1;
	while (*nptr == 32 || (9 <= *nptr && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	nbr = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		new = ft_check_new(nbr, ft_ctoi(*nptr, sign));
		if (new == 10 || new == -10)
			return (0);
		nbr = nbr * 10 + new;
		nptr++;
	}
	return (1);
}

static int	ft_ctoi(int c, int sign)
{
	return (sign * (c - '0'));
}

static int	ft_check_new(int nbr, int new)
{
	int	temp;
	int	check_nbr;
	int	check_new;

	temp = nbr * 10 + new;
	check_nbr = temp / 10;
	check_new = temp % 10;
	if (check_nbr == nbr && check_new == new)
		return (new);
	else if (nbr > 0)
		return (10);
	else
		return (-10);
}
