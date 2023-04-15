/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 22:26:17 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/12 16:27:21 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

void	ft_add_sep(int size, char *dest, char **src, char *sep)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i > 0)
			ft_strcat(dest, sep);
		ft_strcat(dest, src[i]);
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		i_len;
	int		j_len;

	if (size <= 0)
	{
		dest = (char *)malloc(sizeof(char) * 1);
		*dest = 0;
		return (dest);
	}
	i = 0;
	i_len = 0;
	while (i < size)
	{
		i_len += ft_get_len(strs[i]);
		i++;
	}
	j_len = 1 + i_len + (ft_get_len(sep) * (size - 1));
	dest = (char *)malloc(sizeof(char) * j_len);
	if (dest == 0)
		return (0);
	dest[0] = '\0';
	ft_add_sep(size, dest, strs, sep);
	return (dest);
}
