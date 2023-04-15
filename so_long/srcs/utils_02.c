/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:53:37 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/06 16:41:14 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	t;
	size_t			len;
	size_t			i;

	t = c;
	len = ft_strlen((char *)s);
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

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		exit(1);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!s1_len && !s2_len)
		return (ft_strdup(""));
	else
		len = s1_len + s2_len + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		exit(1);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (start >= s_len || !len)
		return (ft_strdup(""));
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

char	*ft_itoa(size_t num)
{
	char	*arr;
	size_t	len;
	size_t	tmp;

	if (!num)
		return (ft_strdup("0"));
	len = 0;
	tmp = num;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
		exit(1);
	arr[len] = '\0';
	while (len)
	{
		arr[--len] = (num % 10) + 48;
		num /= 10;
	}
	return (arr);
}
