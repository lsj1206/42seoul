/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 16:19:06 by seojulee          #+#    #+#             */
/*   Updated: 2022/12/27 10:51:53 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_init(char **remain)
{
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	if (*remain == 0)
	{
		*remain = gnl_strdup("");
		if (!*remain)
		{
			free(buf);
			return (0);
		}
	}
	return (buf);
}

int	gnl_read(int fd, char **remain, char *buf)
{
	char	*tmp;
	int		read_value;

	read_value = read(fd, buf, BUFFER_SIZE);
	if (read_value == -1 || (read_value == 0 && *remain[0] == '\0'))
	{
		free(*remain);
		free(buf);
		buf = 0;
		*remain = 0;
		return (-1);
	}
	buf[read_value] = '\0';
	tmp = *remain;
	*remain = gnl_strjoin(*remain, buf);
	free(tmp);
	tmp = 0;
	if (!(*remain))
	{
		free(buf);
		*remain = 0;
		return (-1);
	}
	return (read_value);
}

char	*gnl_make_line(char **remain)
{
	char	*str;
	char	*tmp;
	size_t	i;

	tmp = *remain;
	str = 0;
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	*remain = gnl_substr(tmp, (i + 1), (gnl_strlen(tmp) - i - 1));
	if (!(*remain))
	{
		free(tmp);
		tmp = 0;
		*remain = 0;
		return (0);
	}
	str = gnl_substr(tmp, 0, (i + 1));
	free(tmp);
	tmp = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	char		*str;
	char		*buf;
	int			i;

	buf = gnl_init(&remain);
	if (!buf)
		return (0);
	while (!gnl_strchr(remain, '\n'))
	{
		i = gnl_read(fd, &remain, buf);
		if (i == -1)
			return (0);
		if (i < BUFFER_SIZE)
			break ;
	}
	free(buf);
	str = gnl_make_line(&remain);
	if (!str)
	{
		free(remain);
		remain = 0;
	}
	return (str);
}
