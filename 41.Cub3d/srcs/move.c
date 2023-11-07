/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:03:38 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:10:07 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	move_right(t_data *d, double speed)
{
	double	x;
	double	y;

	x = d->v.pos_x + d->v.plane_x * speed;
	if (d->map[(int)d->v.pos_y][(int)x] < 1)
		d->v.pos_x = x;
	y = d->v.pos_y + d->v.plane_y * speed;
	if (d->map[(int)y][(int)d->v.pos_x] < 1)
		d->v.pos_y = y;
	return (1);
}

int	move_left(t_data *d, double speed)
{
	double	x;
	double	y;

	x = d->v.pos_x - d->v.plane_x * speed;
	if (d->map[(int)d->v.pos_y][(int)x] < 1)
		d->v.pos_x = x;
	y = d->v.pos_y - d->v.plane_y * speed;
	if (d->map[(int)y][(int)d->v.pos_x] < 1)
		d->v.pos_y = y;
	return (1);
}

int	move_backward(t_data *d, double speed)
{
	double	x;
	double	y;

	x = d->v.pos_x - d->v.dir_x * speed;
	if (d->map[(int)d->v.pos_y][(int)x] < 1)
		d->v.pos_x = x;
	y = d->v.pos_y - d->v.dir_y * speed;
	if (d->map[(int)y][(int)d->v.pos_x] < 1)
		d->v.pos_y = y;
	return (1);
}

int	move_forward(t_data *d, double speed)
{
	double	x;
	double	y;

	x = d->v.pos_x + d->v.dir_x * speed;
	if (d->map[(int)d->v.pos_y][(int)x] < 1)
		d->v.pos_x = x;
	y = d->v.pos_y + d->v.dir_y * speed;
	if (d->map[(int)y][(int)d->v.pos_x] < 1)
		d->v.pos_y = y;
	return (1);
}
