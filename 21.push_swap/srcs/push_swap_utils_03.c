/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_03.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:11:02 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/16 15:04:22 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
