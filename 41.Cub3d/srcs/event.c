/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:15:30 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:36:59 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	change_view(t_data *d, double speed)
{
	double	temp;

	if (d->dir == 1 || d->dir == 4)
		speed *= -1;
	temp = d->v.dir_x;
	d->v.dir_x = d->v.dir_x * cos(speed) - d->v.dir_y * sin(speed);
	d->v.dir_y = temp * sin(speed) + d->v.dir_y * cos(speed);
	temp = d->v.plane_x;
	d->v.plane_x = d->v.plane_x * cos(speed) - d->v.plane_y * sin(speed);
	d->v.plane_y = temp * sin(speed) + d->v.plane_y * cos(speed);
	return (1);
}

int	press_key(int key, t_data *d)
{
	double	move_speed;
	double	rot_speed;

	move_speed = 0.11;
	rot_speed = 0.03;
	if (key == KEY_ESC)
		return (exit_process(d));
	else if (key == KEY_W)
		return (move_forward(d, move_speed));
	else if (key == KEY_A)
		return (move_left(d, move_speed));
	else if (key == KEY_S)
		return (move_backward(d, move_speed));
	else if (key == KEY_D)
		return (move_right(d, move_speed));
	else if (key == KEY_LEFT)
		return (change_view(d, -rot_speed));
	else if (key == KEY_RIGHT)
		return (change_view(d, rot_speed));
	return (0);
}
