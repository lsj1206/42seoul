/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:37 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/06 16:41:13 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < len && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

static size_t	cnt_row(const char *s, char c)
{
	size_t	cnt;
	size_t	len;
	size_t	i;

	cnt = 0;
	len = ft_strlen(s);
	if (!len)
		return (0);
	i = 0;
	if (s[i] != c)
		cnt++;
	while (i < len)
	{
		if (s[i] == c)
			if (s[i + 1] != c && (i + 1) != len)
				cnt++;
		i++;
	}
	return (cnt);
}

static char	*str_slicing(const char *s, char c, size_t *st)
{
	size_t	i;
	size_t	j;

	i = *st;
	while (s[i] == c && s[i])
		i++;
	j = i;
	while (s[j] != c && s[j])
		j++;
	*st = j;
	return (ft_substr(s, i, j - i));
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	row;
	size_t	i;
	size_t	st;

	row = cnt_row(s, c);
	str = (char **)malloc(sizeof(char *) * (row + 1));
	if (!str)
		exit(1);
	i = 0;
	st = 0;
	while (i < row && row)
	{
		str[i] = str_slicing(s, c, &st);
		if (!str[i])
			exit(1);
		i++;
	}
	str[row] = 0;
	return (str);
}
