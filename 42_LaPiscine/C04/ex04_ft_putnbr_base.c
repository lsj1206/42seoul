/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 11:06:29 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/05 16:05:45 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_str_overlap(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

long long	ft_base_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	if (ft_str_overlap(str))
		return (0);
	if (i == 1)
		return (0);
	return (i);
}

void	ft_rec(long long n, long long len, char *base)
{
	char	tmp;

	if (n == 0)
		return ;
	ft_rec(n / len, len, base);
	tmp = base[n % len];
	write(1, &tmp, 1);
}

void	ft_nbr_base(long long nbr, char *base)
{
	long long	obase;

	obase = ft_base_len(base);
	if (obase == 0)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	else if (nbr == 0)
		write(1, &base[0], 1);
	ft_rec(nbr, obase, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	ft_nbr_base(nbr, base);
}
