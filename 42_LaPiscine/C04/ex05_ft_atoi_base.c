/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:21:32 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/05 20:25:01 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_overlap(char *str)
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

int	ft_base_ck(char *str)
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
	if (ft_overlap(str))
		return (0);
	if (i == 1)
		return (0);
	return (i);
}

char	*ft_atoi_ck(char *str, int *minus)
{
	*minus = 1;
	while (*str && (*str == 32 || (9 <= *str && *str <= 13)))
			str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			*minus *= -1;
		str++;
	}
	return (str);
}

int	ft_atoi_b(char *str, int len, char *base)
{
	int	value;
	int	flag;
	int	i;

	value = 0;
	while (*str)
	{
		i = 0;
		flag = 0;
		while (base[i])
		{
			if (*str == base[i])
			{
				value = (value * len) + i;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			return (value);
		str++;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	obase;
	int	value;
	int	minus;

	minus = 0;
	obase = ft_base_ck(base);
	str = ft_atoi_ck(str, &minus);
	value = ft_atoi_b(str, obase, base);
	return (value * minus);
}
