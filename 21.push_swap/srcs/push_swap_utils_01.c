/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:59:24 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/14 12:29:03 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 || *s2)
	{
		a = *s1;
		b = *s2;
		if (a == 0 && b == 0)
			return (0);
		if (a != b)
			return (1);
		s1++;
		s2++;
	}
	return (0);
}

long long	ft_atoi(const char *str)
{
	long long	value;
	long long	minus;
	long long	temp;

	value = 0;
	minus = 1;
	while (*str == 32 || (8 < *str && *str < 14))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		temp = value;
		value = (value * 10) + (*str - '0');
		if (temp > value && minus == 1)
			error_print();
		if (temp > value && minus == -1)
			error_print();
		str++;
	}
	return (value * minus);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < len && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
