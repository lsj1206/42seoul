/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:19:39 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:17:15 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_map_name(t_db *db, int ac, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (ac != 2)
		err_printer(db, 4);
	if (len < 4)
		err_printer(db, 3);
	if (str[len - 4] != '.')
		err_printer(db, 3);
	if (str[len - 3] != 'b')
		err_printer(db, 3);
	if (str[len - 2] != 'e')
		err_printer(db, 3);
	if (str[len - 1] != 'r')
		err_printer(db, 3);
}

void	err_map_data(t_db *db, char **map)
{
	int		i;
	int		j;

	err_rectangular(db, map, db->map_w);
	err_outer_wall(db, map, db->map_w, db->map_h);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			err_component(db, map[i][j]);
	}
	if (!(db->err.is_e && db->err.is_p))
		err_printer(db, 3);
	else
	{
		if (!db->err.is_c)
			err_printer(db, 3);
		if (db->err.is_e > 1 || db->err.is_p > 1)
			err_printer(db, 3);
	}
	db->item_cnt = db->err.is_c;
	pos_init(db);
	err_map_validation(db);
}

void	err_img_data(t_db *db)
{
	if (!db->img.pl[0])
		err_printer(db, 2);
	if (!db->img.pl[1])
		err_printer(db, 2);
	if (!db->img.pl[2])
		err_printer(db, 2);
	if (!db->img.pl[3])
		err_printer(db, 2);
	if (!db->img.item)
		err_printer(db, 2);
	if (!db->img.road)
		err_printer(db, 2);
	if (!db->img.wall)
		err_printer(db, 2);
	if (!db->img.exit)
		err_printer(db, 2);
}
