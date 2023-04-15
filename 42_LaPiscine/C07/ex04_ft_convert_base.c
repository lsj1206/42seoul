/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 09:58:01 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/12 10:34:54 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_base_ck(char *str);
int	ft_atoi_base(char *str, char *base);

int	ft_rec_len(int nbr, int bt_len, int len)
{
	if (nbr == 0)
		return (len);
	ft_rec_len(nbr / bt_len, bt_len, len + 1);
	return (0);
}

char	*ft_str_swap(char *str, int size)
{
	int	tmp;
	int	i;

	i = 0;
	while (i < (size / 2))
	{
		tmp = str[i];
		str[i] = str[(size - 1) - i];
		str[(size - 1) - i] = tmp;
		i++;
	}
	return (str);
}

char	*ft_itoa(long long nbr, int len, char *base, char *str)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	if (nbr < 0)
	{
		minus = 1;
		nbr *= -1;
	}
	while (nbr)
	{
		str[i] = base[nbr % len];
		nbr /= len;
		i++;
	}
	if (minus == 1)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	str = ft_str_swap(str, i);
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*str;
	int		inbr;
	int		bt_len;
	int		len;

	bt_len = ft_base_ck(base_to);
	if (!(ft_base_ck(base_from)) || !(bt_len))
		return (0);
	inbr = ft_atoi_base(nbr, base_from);
	len = ft_rec_len(inbr, bt_len, 0);
	str = (char *)malloc(sizeof(char) * (len + 2));
	str[0] = '\0';
	if (str == 0)
		return (0);
	if (inbr == 0)
	{
		str[0] = base_to[0];
		str[1] = '\0';
	}
	else
		str = ft_itoa(inbr, bt_len, base_to, str);
	return (str);
}
