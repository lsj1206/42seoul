/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:26:42 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:22:11 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_init(t_db *db)
{
	t_pos	pos;

	pos.y = 0;
	while (pos.y < db->map_h)
	{
		pos.x = 0;
		while (pos.x < db->map_w)
		{
			if (db->map[pos.y][pos.x] == 'P')
			{
				db->player.x = pos.x;
				db->player.y = pos.y;
			}
			if (db->map[pos.y][pos.x] == 'E')
			{
				db->exit.x = pos.x;
				db->exit.y = pos.y;
			}
			pos.x++;
		}
		pos.y++;
	}
}

static int	key_mapping(int key)
{
	int	tmp;

	tmp = key;
	if (key == 126)
		tmp = KEY_W;
	if (key == 123)
		tmp = KEY_A;
	if (key == 125)
		tmp = KEY_S;
	if (key == 124)
		tmp = KEY_D;
	return (tmp);
}

static int	is_wall(t_db *db, int x, int y)
{
	if (db->map[y][x] != '1')
		return (1);
	else
		return (0);
}

int	key_press(int key, t_db *db)
{
	t_pos	pos;

	pos.x = db->player.x;
	pos.y = db->player.y;
	key = key_mapping(key);
	if (!(0 <= key && key < 3) && !(key == KEY_W || key == KEY_ESC))
		return (0);
	if (key == KEY_ESC)
		exit_game(db);
	if (key == KEY_W && is_wall(db, db->player.x, (db->player.y - 1)))
		move(db, pos, db->player.x, (db->player.y - 1));
	if (key == KEY_A && is_wall(db, (db->player.x - 1), db->player.y))
		move(db, pos, (db->player.x - 1), db->player.y);
	if (key == KEY_S && is_wall(db, db->player.x, (db->player.y + 1)))
		move(db, pos, db->player.x, (db->player.y + 1));
	if (key == KEY_D && is_wall(db, (db->player.x + 1), db->player.y))
		move(db, pos, (db->player.x + 1), db->player.y);
	win_printer(db, key);
	return (1);
}

void	move(t_db *db, t_pos pos, int x, int y)
{
	if (db->map[y][x] == 'E' && db->item_cnt < 1)
	{
		write(1, "Clear!!!\n", 10);
		exit_game(db);
	}
	else if (db->map[y][x] == 'E')
		return ;
	if (db->map[y][x] == 'C')
		db->item_cnt--;
	db->map[y][x] = 'P';
	db->map[pos.y][pos.x] = '0';
	db->player.x = x;
	db->player.y = y;
	db->move_cnt++;
	move_printer(db);
}
