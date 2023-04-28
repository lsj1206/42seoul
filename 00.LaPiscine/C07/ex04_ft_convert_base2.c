/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 10:27:03 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/10 15:28:38 by seojulee         ###   ########.fr       */
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

int	ft_atoi_ck(char *str, int *minus)
{
	int	i;

	i = 0;
	*minus = 1;
	while (str[i] && (str[i] == 32 || (9 <= str[i] && str[i] <= 13)))
			i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			*minus *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi_b(char *str, int i, int len, char *base)
{
	int	value;
	int	flag;
	int	j;

	value = 0;
	while (str[i])
	{
		j = 0;
		flag = 0;
		while (base[j])
		{
			if (str[i] == base[j])
			{
				value = (value * len) + j;
				flag = 1;
			}
			j++;
		}
		if (flag == 0)
			return (value);
		i++;
	}
	return (value);
}

int	ft_atoi_base(char *str, char *base)
{
	int	obase;
	int	value;
	int	minus;
	int	i;

	i = 0;
	minus = 0;
	value = 0;
	obase = ft_base_ck(base);
	if (obase > 0)
		i = ft_atoi_ck(str, &minus);
		value = ft_atoi_b(str, i, obase, base);
	return (value * minus);
}
