/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 14:22:22 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:12:54 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_rectangular(t_db *db, char **map, int x)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j != x)
			err_printer(db, 3);
	}
}

void	err_outer_wall(t_db *db, char **map, int x, int y)
{
	int	i;

	i = -1;
	while (map[0][++i] && map[y - 1][i])
	{
		if (map[0][i] != '1')
			err_printer(db, 3);
		if (map[y - 1][i] != '1')
			err_printer(db, 3);
	}
	i = -1;
	while (map[++i])
	{
		if (map[i][0] != '1' || map[i][x - 1] != '1')
			err_printer(db, 3);
	}
}

void	err_component(t_db *db, int c)
{
	if (c == '0' || c == '1')
		return ;
	if (c == 'C')
	{
		db->err.is_c++;
		return ;
	}
	if (c == 'E')
	{
		db->err.is_e++;
		return ;
	}
	if (c == 'P')
	{
		db->err.is_p++;
		return ;
	}
	err_printer(db, 3);
}

void	err_map_validation(t_db *db)
{
	visited_init(db);
	dfs(db, db->player.x, db->player.y);
	if (!db->err.is_valid || db->err.is_c > 0)
		err_printer(db, 3);
	free_v_arr(db);
}
