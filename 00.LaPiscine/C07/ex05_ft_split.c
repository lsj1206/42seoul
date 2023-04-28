/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojuleei <seojuleei@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:25:24 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/12 20:46:13 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ck_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_ck_len(char *str, char *sep, int flag)
{
	int	i;
	int	len;
	int	s_flag;

	i = 0;
	len = 1;
	s_flag = 1;
	while (ft_ck_sep(str[i], sep))
		i++;
	while (str[i])
	{
		s_flag = 0;
		if (ft_ck_sep(str[i], sep) && (!(ft_ck_sep(str[i + 1], sep))
				&& str[i + 1] != 0))
			len++;
		i++;
	}
	if (s_flag == 1)
		len = 0;
	if (flag == 1)
		return (len);
	return (i);
}

void	ft_put_split(char **dest, char *str, char *sep, int size)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (ft_ck_sep(str[k], sep))
		k++;
	while (++i < size)
	{
		j = 0;
		while (str[j + k])
		{
			if (ft_ck_sep(str[j + k], sep) && !ft_ck_sep(str[j + k + 1], sep))
				break ;
			else if (!ft_ck_sep(str[j + k], sep))
				dest[i][j] = str[j + k];
			j++;
		}
		dest[i][j] = 0;
		k += j + 1;
	}
	dest[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		sep_len;
	int		str_len;
	int		i;

	str_len = ft_ck_len(str, charset, 0);
	sep_len = ft_ck_len(str, charset, 1);
	dest = (char **)malloc(sizeof(char *) * (sep_len + 1));
	if (dest == 0)
		return (0);
	i = 0;
	while (i < sep_len + 1)
	{
		dest[i] = (char *)malloc(sizeof(char) * (str_len + 1));
		if (*dest == 0)
			return (0);
		i++;
	}
	ft_put_split(dest, str, charset, sep_len);
	return (dest);
}
