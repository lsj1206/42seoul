/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_component.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:51:47 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:32:49 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_dir(t_data *d, char **map, int x, int y)
{
	if (d->dir)
		err_handler(d, ERR_MAP, sstr_free(map));
	if (map[y][x] == 'S')
		d->dir = 1;
	else if (map[y][x] == 'N')
		d->dir = 2;
	else if (map[y][x] == 'E')
		d->dir = 3;
	else if (map[y][x] == 'W')
		d->dir = 4;
	d->v.pos_x = x;
	d->v.pos_y = y;
}

static void	is_component(t_data *d, char **map, int x, int y)
{
	if (map[y][x] == ' ')
		return ;
	else if (map[y][x] == '0')
		return ;
	else if (map[y][x] == '1')
		return ;
	else if (map[y][x] == 'S')
		check_dir(d, map, x, y);
	else if (map[y][x] == 'N')
		check_dir(d, map, x, y);
	else if (map[y][x] == 'E')
		check_dir(d, map, x, y);
	else if (map[y][x] == 'W')
		check_dir(d, map, x, y);
	else
		err_handler(d, ERR_MAP, sstr_free(map));
}

int	vaild_component(t_data *d, char **map)
{
	int	map_width;
	int	width;
	int	x;
	int	y;

	map_width = 0;
	y = -1;
	while (++y < d->map_height)
	{
		width = ft_strlen(map[y]);
		if (map_width < width)
			map_width = width;
		x = -1;
		while (++x < width)
			is_component(d, map, x, y);
	}
	if (!d->dir)
		err_handler(d, ERR_MAP, sstr_free(map));
	return (map_width);
}
