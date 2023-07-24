/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dajeon <dajeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 20:33:36 by dajeon            #+#    #+#             */
/*   Updated: 2023/07/24 20:33:37 by dajeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_arrsort_merge(int *buf, int *array, int start, int end);
int	ft_arrcpy(int *dst, int *src, int start, int end);

int	ft_arrsort(int *array, int size)
{
	int	*buf;

	buf = (int *)malloc(sizeof(int) * size);
	if (buf == NULL)
		return (-1);
	if (ft_arrsort_merge(buf, array, 0, size) < 0)
	{
		free(buf);
		return (-1);
	}
	free(buf);
	return (0);
}

int	merge(int *buf, int *array, int start, int end)
{
	int	mid;
	int	i;
	int	j;
	int	k;

	mid = (end + start) / 2;
	i = start;
	j = mid;
	k = start;
	while (i < mid && j < end)
	{
		if (array[i] < array[j])
			buf[k++] = array[i++];
		else
			buf[k++] = array[j++];
	}
	while (i < mid)
		buf[k++] = array[i++];
	while (j < end)
		buf[k++] = array[j++];
	ft_arrcpy(array, buf, start, end);
	return (0);
}

int	ft_arrsort_merge(int *buf, int *array, int start, int end)
{
	int	mid;

	if (end - start > 1)
	{
		mid = (end + start) / 2;
		ft_arrsort_merge(buf, array, mid, end);
		ft_arrsort_merge(buf, array, start, mid);
		merge(buf, array, start, end);
	}
	return (0);
}
