/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:34:24 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:26:11 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_db	db_init(t_db *db)
{
	db->mlx_p = 0;
	db->win_p = 0;
	db->map = 0;
	db->v_arr = 0;
	db->map_w = 0;
	db->map_h = 0;
	db->item_cnt = 0;
	db->move_cnt = 0;
	db->err.is_enter = 0;
	db->err.is_c = 0;
	db->err.is_e = 0;
	db->err.is_p = 0;
	db->err.is_valid = 0;
	db->player.x = 0;
	db->player.y = 0;
	db->exit.x = 0;
	db->exit.y = 0;
	return (*db);
}

void	win_printer(t_db *db, int key)
{
	int		x;
	int		y;

	y = 0;
	while (y < db->map_h)
	{
		x = 0;
		while (x < db->map_w)
		{
			img_mapping(db, x, y, (key % 10));
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_db	db;
	int		wid;
	int		hei;

	db = db_init(&db);
	map_init(&db, ac, av);
	db.mlx_p = mlx_init();
	if (!db.mlx_p)
		err_printer(&db, 1);
	wid = db.map_w * PX;
	hei = db.map_h * PX;
	db.win_p = mlx_new_window(db.mlx_p, wid, hei, "so_long");
	if (!db.win_p)
		err_printer(&db, 1);
	img_init(&db);
	win_printer(&db, 2);
	mlx_hook(db.win_p, 17, 0, &exit_game, &db);
	mlx_hook(db.win_p, 2, 0, &key_press, &db);
	mlx_loop(db.mlx_p);
	return (0);
}
