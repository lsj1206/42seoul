/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:04:53 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 18:00:06 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**resize_map(t_data *d, char **map, int width)
{
	char	*temp;
	char	*space;
	int		sp_len;
	int		y;

	y = -1;
	while (++y < d->map_height)
	{
		temp = map[y];
		sp_len = width - ft_strlen(temp);
		space = (char *)malloc(sizeof(char) * (sp_len + 1));
		if (!space)
			err_handler(d, ERR_MEM, sstr_free(map));
		space = ft_memset(space, ' ', sp_len);
		map[y] = str_fjoin(d, temp, space);
		map[y][width] = '\0';
	}
	return (map);
}

static void	convert_map(t_data *d, char **src_map, int width)
{
	int	x;
	int	y;

	src_map = resize_map(d, src_map, width);
	d->map = (int **)malloc(sizeof(int *) * d->map_height);
	if (!d->map)
		err_handler(d, ERR_MEM, sstr_free(src_map));
	y = -1;
	while (++y < d->map_height)
	{
		d->map[y] = (int *)malloc(sizeof(int) * width);
		x = -1;
		while (++x < width)
		{
			if (src_map[y][x] < '0')
				d->map[y][x] = 2;
			else if (src_map[y][x] > '1')
				d->map[y][x] = -1;
			else
				d->map[y][x] = src_map[y][x] - 48;
		}
	}
	sstr_free(src_map);
}

static void	vaild_map(t_data *d, char *map_tmp, int read_cnt)
{
	char	**map;
	int		width;

	map = ft_split(map_tmp, '\n');
	if (!map)
		err_handler(d, ERR_MEM, map_tmp);
	free(map_tmp);
	d->map_height = sstr_len(map);
	if (read_cnt != d->map_height)
		err_handler(d, ERR_MAP, sstr_free(map));
	width = vaild_component(d, map);
	if (valid_outerwall(d, map))
		err_handler(d, ERR_MAP, sstr_free(map));
	convert_map(d, map, width);
}

void	parse_map(t_data *d, int fd)
{
	char	*map_tmp;
	char	*line;
	int		read_cnt;

	map_tmp = str_alloc(d, 0);
	read_cnt = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) < 2 && !ft_strlen(map_tmp))
		{
			free(line);
			continue ;
		}
		map_tmp = str_fjoin(d, map_tmp, line);
		read_cnt++;
	}
	if (!line && !read_cnt)
		err_handler(d, ERR_MAP, map_tmp);
	vaild_map(d, map_tmp, read_cnt);
}
