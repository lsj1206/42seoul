/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:53:20 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 18:04:51 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*str_alloc(t_data *d, char *contents)
{
	char	*str;
	int		len;

	if (!contents)
		len = 0;
	else
		len = ft_strlen(contents);
	if (len <= 0)
		str = ft_strdup("");
	else
		str = ft_strdup(contents);
	if (!str)
		err_handler(d, ERR_MEM, 0);
	return (str);
}

char	*str_fjoin(t_data *d, char *str1, char *str2)
{
	char	*str;
	char	*tmp1;
	char	*tmp2;

	if (!str1)
		str1 = str_alloc(d, 0);
	if (!str2)
		str2 = str_alloc(d, 0);
	tmp1 = str1;
	tmp2 = str2;
	str = ft_strjoin(str1, str2);
	free(tmp1);
	free(tmp2);
	if (!str)
		err_handler(d, ERR_MEM, 0);
	return (str);
}

char	**sstr_alloc(t_data *d, int len)
{
	char	**str;
	int		i;

	str = (char **)malloc(sizeof(char *) * (len + 1));
	if (!str)
		err_handler(d, ERR_MEM, 0);
	i = 0;
	while (i < len)
	{
		str[i] = str_alloc(d, 0);
		i++;
	}
	str[len] = 0;
	return (str);
}

int	sstr_len(char **sstr)
{
	int	len;

	if (!sstr)
		return (0);
	len = 0;
	while (1)
	{
		if (!sstr[len])
			break ;
		len++;
	}
	return (len);
}

void	*sstr_free(char **sstr)
{
	int	i;

	if (!sstr)
		return (0);
	i = sstr_len(sstr);
	while (i)
		free(sstr[--i]);
	free(sstr);
	return (0);
}
