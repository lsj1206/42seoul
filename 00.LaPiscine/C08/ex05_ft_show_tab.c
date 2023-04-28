/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:38:49 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/13 15:26:14 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

long long	ft_nbr(long long n, int *arr)
{
	long long	tmp;
	long long	i;

	i = 0;
	while (n)
	{
		tmp = n % 10;
		arr[i] = tmp;
		n /= 10;
		i++;
	}
	return (i - 1);
}

void	ft_putnbr(long long nb)
{
	long long	i;
	int			arr[10];

	i = 10;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	i = ft_nbr(nb, arr);
	while (i >= 0 && nb != 0)
	{
		arr[i] += '0';
		write(1, &arr[i], 1);
		i--;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while (par->str)
	{
		ft_putstr(par->str);
		write(1, "\n", 1);
		ft_putnbr(par->size);
		write(1, "\n", 1);
		ft_putstr(par->copy);
		write(1, "\n", 1);
		par++;
	}
}
