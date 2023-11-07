/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 18:07:12 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 17:35:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	insert_check(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!d->t.path[i])
			err_handler(d, ERR_ARG, 0);
	if (!d->t.celling)
		err_handler(d, ERR_ARG, 0);
	d->t.celling--;
	if (!d->t.floor)
		err_handler(d, ERR_ARG, 0);
	d->t.floor--;
}

static void	insert_arg(t_data *d, char *id, char *path)
{
	if (!ft_strncmp("SO", id, 2))
	{
		free(d->t.path[0]);
		d->t.path[0] = str_alloc(d, path);
	}
	else if (!ft_strncmp("NO", id, 2))
	{
		free(d->t.path[1]);
		d->t.path[1] = str_alloc(d, path);
	}
	else if (!ft_strncmp("EA", id, 2))
	{
		free(d->t.path[2]);
		d->t.path[2] = str_alloc(d, path);
	}
	else if (!ft_strncmp("WE", id, 2))
	{
		free(d->t.path[3]);
		d->t.path[3] = str_alloc(d, path);
	}
	else if (!ft_strncmp("C", id, 1))
		d->t.celling = parse_rgb(d, path);
	else if (!ft_strncmp("F", id, 1))
		d->t.floor = parse_rgb(d, path);
	free(path);
}

static int	valid_arg(t_data *d, char *id, char *line, int i)
{
	char	*path;
	int		len;

	while (line[i] == ' ')
		i++;
	len = ft_strlen(line);
	len--;
	path = ft_substr(line, i, (len - i));
	if (!path)
		err_handler(d, ERR_MEM, line);
	free(line);
	insert_arg(d, id, path);
	return (1);
}

static int	check_arg(t_data *d, char *line)
{
	int	value;

	value = -1;
	if (ft_strlen(line) == 1 && line[0] == '\n')
		value = 0;
	else if (!ft_strncmp("SO", line, 2))
		return (valid_arg(d, "SO", line, 2));
	else if (!ft_strncmp("NO", line, 2))
		return (valid_arg(d, "NO", line, 2));
	else if (!ft_strncmp("EA", line, 2))
		return (valid_arg(d, "EA", line, 2));
	else if (!ft_strncmp("WE", line, 2))
		return (valid_arg(d, "WE", line, 2));
	else if (!ft_strncmp("C", line, 1))
		return (valid_arg(d, "C", line, 1));
	else if (!ft_strncmp("F", line, 1))
		return (valid_arg(d, "F", line, 1));
	free(line);
	return (value);
}

void	parse_arg(t_data *d, int fd)
{
	char	*line;
	int		value;
	int		arg_cnt;

	d->t.path = sstr_alloc(d, 4);
	arg_cnt = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		value = check_arg(d, line);
		if (value == -1)
			err_handler(d, ERR_ARG, 0);
		arg_cnt += value;
		if (arg_cnt == 6)
			break ;
	}
	if (!line)
		err_handler(d, ERR_ARG, 0);
	insert_check(d);
}
