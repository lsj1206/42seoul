/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:12:41 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/09 15:28:31 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_all(t_db *db)
{
	if (db->mlx_p)
		free_mlx(db);
	if (db->map)
		free_map(db);
	if (db->v_arr)
		free_v_arr(db);
}

void	free_map(t_db *db)
{
	int	i;

	i = db->map_h;
	while (i > -1)
	{
		free(db->map[i]);
		i--;
	}
	free(db->map);
	db->map = 0;
}

void	free_v_arr(t_db *db)
{
	int	i;

	i = (db->map_h - 1);
	while (i > -1)
	{
		free(db->v_arr[i]);
		i--;
	}
	free(db->v_arr);
	db->v_arr = 0;
}

void	free_mlx(t_db *db)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(db->mlx_p, db->img.pl[i]);
		i++;
	}
	mlx_destroy_image(db->mlx_p, db->img.exit);
	mlx_destroy_image(db->mlx_p, db->img.wall);
	mlx_destroy_image(db->mlx_p, db->img.road);
	mlx_destroy_image(db->mlx_p, db->img.item);
	mlx_destroy_window(db->mlx_p, db->win_p);
}
