/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:27:28 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:18:58 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_db *db, int ac, char **av)
{
	int	fd;

	err_map_name(db, ac, av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		err_printer(db, 5);
	map_maker(db, fd);
	err_map_data(db, db->map);
}

void	map_maker(t_db *db, int fd)
{
	char	*str;
	int		tmp;
	int		i;

	str = map_read(db, fd);
	db->map = ft_split(str, '\n');
	db->map_w = ft_strlen(db->map[0]);
	tmp = 0;
	while (db->map[tmp])
		tmp++;
	db->map_h = tmp;
	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			db->err.is_enter++;
	if (db->map_h != db->err.is_enter)
		err_printer(db, 3);
	free(str);
}

char	*map_read(t_db *db, int fd)
{
	char	*str;
	char	*tmp;
	char	buf[2];
	int		read_byte;

	str = ft_strdup("");
	while (1)
	{
		read_byte = read(fd, &buf[0], 1);
		buf[1] = '\0';
		if (read_byte < 1)
			break ;
		tmp = str;
		str = ft_strjoin(str, buf);
		free(tmp);
	}
	if (read_byte == -1 || (str[0] == 0 && !read_byte))
	{
		free(str);
		err_printer(db, 3);
	}
	return (str);
}

void	img_init(t_db *db)
{
	db->img.pl[3] = xfti(db, db->img.pl[3], "./textures/up.xpm");
	db->img.pl[0] = xfti(db, db->img.pl[0], "./textures/left.xpm");
	db->img.pl[1] = xfti(db, db->img.pl[1], "./textures/down.xpm");
	db->img.pl[2] = xfti(db, db->img.pl[2], "./textures/right.xpm");
	db->img.item = xfti(db, db->img.item, "./textures/item.xpm");
	db->img.road = xfti(db, db->img.road, "./textures/road.xpm");
	db->img.wall = xfti(db, db->img.wall, "./textures/wall.xpm");
	db->img.exit = xfti(db, db->img.exit, "./textures/exit.xpm");
	err_img_data(db);
}

void	img_mapping(t_db *db, int x, int y, int dir)
{
	if (db->map[y][x] == '0')
		pitw(db, db->img.road, x, y);
	if (db->map[y][x] == '1')
		pitw(db, db->img.wall, x, y);
	if (db->map[y][x] == 'C')
		pitw(db, db->img.item, x, y);
	if (db->map[y][x] == 'E')
		pitw(db, db->img.exit, x, y);
	if (db->map[y][x] == 'P')
		pitw(db, db->img.pl[dir], x, y);
}
