/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:35:19 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/06 16:02:52 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_negative_n(int n, int *arr)
{
	int	tmp;
	int	i;

	i = 0;
	write(1, "-", 1);
	while (n)
	{
		tmp = n % 10;
		tmp *= -1;
		arr[i] = tmp;
		n /= 10;
		i++;
	}
	return (i - 1);
}

int	ft_positive_n(int n, int *arr)
{
	int	tmp;
	int	i;

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

void	ft_putnbr(int nb)
{
	int	arr[10];
	int	i;

	i = 10;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
		i = ft_negative_n(nb, arr);
	else
		i = ft_positive_n(nb, arr);
	while (i >= 0 && nb != 0)
	{
		arr[i] += '0';
		write(1, &arr[i], 1);
		i--;
	}
}
