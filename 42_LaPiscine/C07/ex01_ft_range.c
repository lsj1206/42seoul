/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:26:56 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/12 10:29:18 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_long_range(long long min, long long max)
{
	long long	len;
	long long	i;
	int			*arr;

	i = 0;
	len = max - min;
	if (min >= max)
		return (0);
	arr = (int *)malloc(sizeof(int) * len);
	if (arr == 0)
		return (0);
	while (min < max)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

int	*ft_range(int min, int max)
{
	return (ft_long_range(min, max));
}
