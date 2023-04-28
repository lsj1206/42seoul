/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 09:14:10 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/10 22:28:59 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ult_range(int **range, long long min, long long max)
{
	long long	len;
	long long	i;

	len = max - min;
	*range = 0;
	if (min >= max)
		return (0);
	*range = (int *)malloc(sizeof(int) * len);
	if (*range == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		range[0][i] = min;
		min++;
		i++;
	}
	return (i);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	return (ft_ult_range(range, min, max));
}
