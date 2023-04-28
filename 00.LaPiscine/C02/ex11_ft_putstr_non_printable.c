/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 16:18:09 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/01 13:40:43 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	hex_tr(unsigned char c, unsigned char *a, unsigned char *b)
{
	char			*hex;
	unsigned int	div;
	unsigned int	mod;

	hex = "0123456789abcdef";
	div = c / 16;
	mod = c % 16;
	*a = hex[div];
	*b = hex[mod];
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	a;
	unsigned char	b;

	a = '0';
	b = '0';
	while (*str != '\0')
	{
		if (!(32 <= *str && *str <= 126))
		{
			write(1, "\\", 1);
			hex_tr((unsigned char)*str, &a, &b);
			write(1, &a, 1);
			write(1, &b, 1);
		}
		else
			write(1, str, 1);
		str++;
	}
}
