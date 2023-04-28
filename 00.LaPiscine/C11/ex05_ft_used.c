/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_used.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:26:00 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/14 17:46:47 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

long long	ft_nbr(long long n)
{
	long long	tmp;
	long long	i;
	int			flag;
	char		arr[12];

	i = 11;
	flag = 0;
	if (n < 0)
	{
		n *= -1;
		flag = 1;
	}
	while (n)
	{
		tmp = n % 10;
		arr[i--] = tmp + '0';
		n /= 10;
	}
	if (flag == 1)
		arr[i--] = '-';
	while (i++ < 11)
	{
		write(1, &arr[i], 1);
	}
	return (n);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else
		ft_nbr(nb);
}

int	ft_atoi(char *str)
{
	int	i;
	int	value;
	int	minus;

	i = 0;
	value = 0;
	minus = 1;
	while (str[i] == 32 || (8 < str[i] && str[i] < 14))
			i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		i++;
	}
	return (value * minus);
}
