/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 19:43:23 by seojulee          #+#    #+#             */
/*   Updated: 2022/12/26 10:27:52 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*gnl_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = gnl_strlen((char *)s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*gnl_strchr(const char *s, int c)
{
	unsigned char	t;
	size_t			len;
	size_t			i;

	t = c;
	len = gnl_strlen((char *)s);
	i = 0;
	while (i < len + 1)
	{
		if (*s == t)
			return ((char *)s);
		s++;
		i++;
	}
	return (0);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (0);
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	if (!s1_len && !s2_len)
		return (gnl_strdup(""));
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == 0)
		return (0);
	i = -1;
	while (++i < s1_len)
		str[i] = s1[i];
	i = -1;
	while (++i < s2_len)
		str[i + s1_len] = s2[i];
	str[i + s1_len] = '\0';
	return (str);
}

char	*gnl_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	s_len = gnl_strlen(s);
	if (start >= s_len || !len)
		return (gnl_strdup(""));
	if (len > (s_len - start))
		len = s_len - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
