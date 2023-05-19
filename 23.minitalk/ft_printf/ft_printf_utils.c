/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:08:58 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/06 18:05:28 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*base_init(size_t nbase, size_t upper_flag)
{
	char	*base;

	if (nbase == 8)
		base = "01234567";
	else if (nbase == 10)
		base = "0123456789";
	else if (nbase == 16 && !upper_flag)
		base = "0123456789abcdef";
	else if (nbase == 16 && upper_flag)
		base = "0123456789ABCDEF";
	else
		return (0);
	return (base);
}

size_t	num_len(long long n, size_t nbase)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n)
	{
		n /= nbase;
		len++;
	}
	return (len);
}

char	*num_to_str(long long n, size_t nbase, size_t upper_flag)
{
	char	*base;
	char	*arr;
	size_t	len;
	size_t	minus;

	base = base_init(nbase, upper_flag);
	len = num_len(n, nbase);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	arr[len] = '\0';
	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n *= -1;
	}
	while (len)
	{
		arr[--len] = base[n % nbase];
		n /= nbase;
	}
	if (minus)
		arr[len] = '-';
	return (arr);
}

size_t	num_len_to_unsigned(unsigned long long n, size_t nbase)
{
	size_t	len;

	len = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= nbase;
		len++;
	}
	return (len);
}

char	*addr_to_hex(void *p)
{
	unsigned long long	n;
	char				*base;
	char				*arr;
	size_t				len;

	n = (unsigned long long)p;
	base = base_init(16, 0);
	len = num_len_to_unsigned(n, 16) + 2;
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == 0)
		return (0);
	arr[len] = '\0';
	while (len > 2)
	{
		arr[--len] = base[n % 16];
		n /= 16;
	}
	arr[--len] = 'x';
	arr[--len] = '0';
	return (arr);
}
