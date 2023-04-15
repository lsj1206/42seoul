/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:38:55 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:19 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
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
			exit(1);
		if (temp > value && minus == -1)
			exit(1);
		str++;
	}
	return (value * minus);
}
