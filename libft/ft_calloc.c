/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:57:59 by seojulee          #+#    #+#             */
/*   Updated: 2022/11/25 20:48:27 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	f_size;
	size_t	i;
	char	*arr;

	f_size = count * size;
	if (f_size < 0)
		return (0);
	arr = (char *)malloc(count * size);
	if (arr == 0)
		return (0);
	i = 0;
	while (i < f_size)
		arr[i++] = 0;
	return ((void *)arr);
}
