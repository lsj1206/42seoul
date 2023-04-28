/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:55:37 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/06 16:01:31 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	wrt_comb2(int i, int j, int k, int l)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = i + '0';
	b = j + '0';
	c = k + '0';
	d = l + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (!(a == '9' && b == '8'))
		write(1, ", ", 2);
}

void	slice_comb2(int i, int j)
{
	int	i_n;
	int	i_b;
	int	j_n;
	int	j_b;

	i_n = i / 10;
	i_b = i % 10;
	j_n = j / 10;
	j_b = j % 10;
	wrt_comb2(i_n, i_b, j_n, j_b);
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i <= 98)
	{
		while (j <= 99)
		{
			slice_comb2(i, j);
			j++;
			if (j == 100)
			{
				i++;
				j = i + 1;
			}
		}
	}
}
