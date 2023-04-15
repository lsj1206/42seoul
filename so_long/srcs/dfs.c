/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:16:45 by wmo               #+#    #+#             */
/*   Updated: 2023/03/06 16:40:59 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	visited_init(t_db *db)
{
	int	i;
	int	j;

	db->v_arr = (int **)malloc(sizeof(int *) * db->map_h);
	if (!db->v_arr)
		err_printer(db, 1);
	i = 0;
	while (i < db->map_h)
	{
		j = 0;
		db->v_arr[i] = (int *)malloc(sizeof(int) * db->map_w);
		if (!db->v_arr[i])
			err_printer(db, 1);
		while (j < db->map_w)
		{
			db->v_arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	dfs(t_db *db, int x, int y)
{
	const int	dy[4] = {1, 0, 0, -1};
	const int	dx[4] = {0, 1, -1, 0};
	int			i;

	i = 0;
	if (db->map[y][x] == 'C')
		db->err.is_c--;
	if (x == db->exit.x && y == db->exit.y)
	{
		db->err.is_valid = 1;
		return ;
	}
	db->v_arr[y][x] = 1;
	while (i < 4)
	{
		if (pos_valid(db, x + dx[i], y + dy[i]))
			dfs(db, x + dx[i], y + dy[i]);
		i++;
	}
}

int	pos_valid(t_db *db, int x, int y)
{
	if (y < 1 || x < 1 || y > db->map_h - 1 || x > db->map_w - 1)
		return (0);
	if (db->v_arr[y][x] || db->map[y][x] == '1')
		return (0);
	return (1);
}
