/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abbr_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:10:37 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:22:47 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*xfti(t_db *db, void *img_p, char *str)
{
	int	width;
	int	height;

	img_p = mlx_xpm_file_to_image(db->mlx_p, str, &width, &height);
	if (!img_p)
		err_printer(db, 2);
	return (img_p);
}

int	pitw(t_db *db, void *img_p, int x, int y)
{
	int	i;

	i = mlx_put_image_to_window(db->mlx_p, db->win_p, img_p, x * PX, y * PX);
	return (i);
}
