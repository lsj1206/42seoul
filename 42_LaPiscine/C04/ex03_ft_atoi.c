/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:02:15 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/05 18:59:57 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_check(char *str, int *minus)
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

int	ft_atoi(char *str)
{
	int	value;
	int	minus;

	value = 0;
	minus = 0;
	str = ft_check(str, &minus);
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			value = (value * 10) + (*str - '0');
		else if (!('0' <= *str && *str <= '9'))
			return (value * minus);
		str++;
	}
	return (value * minus);
}
