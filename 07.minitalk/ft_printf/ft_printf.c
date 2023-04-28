/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:10:39 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/06 18:08:34 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	str_len(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

int	spec_check(va_list ap, int i, char *str)
{
	int		value;

	value = 0;
	if (str[i] == 'c')
		value = spec_is_c(ap);
	else if (str[i] == 's')
		value = spec_is_s(ap);
	else if (str[i] == 'p')
		value = spec_is_p(ap);
	else if (str[i] == 'd' || str[i] == 'i')
		value = spec_is_d_i(ap);
	else if (str[i] == 'u')
		value = spec_is_u_x(ap, 10, 0);
	else if (str[i] == 'x')
		value = spec_is_u_x(ap, 16, 0);
	else if (str[i] == 'X')
		value = spec_is_u_x(ap, 16, 1);
	else if (str[i] == '%')
		value = write(1, "%", 1);
	else
		return (-1);
	return (value);
}

int	str_read(va_list ap, int i, char *str, int read_byte)
{
	int		value;

	value = 1;
	while (str[++i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[++i] == '\0')
				return (0);
			value = spec_check(ap, i, str);
			if (value < 0)
				return (value);
			read_byte += value;
		}
		else
		{
			value = write(1, &str[i], 1);
			if (value == -1)
				return (value);
			read_byte++;
		}
	}
	return (read_byte);
}

int	ft_printf(const char *str, ...)
{
	int		read_byte;
	int		i;
	va_list	ap;

	read_byte = 0;
	i = -1;
	va_start(ap, str);
	read_byte = str_read(ap, i, (char *)str, read_byte);
	if (read_byte == -1)
		return (-1);
	va_end(ap);
	return (read_byte);
}
