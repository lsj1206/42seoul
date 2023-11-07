/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:55:46 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:03:49 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static double	get_perp_dist(t_data *d, t_ray *r)
{
	if (r->side)
		return ((r->x.map - d->v.pos_x + (1 - r->x.step) / 2) / r->x.raydir);
	else
		return ((r->y.map - d->v.pos_y + (1 - r->y.step) / 2) / r->y.raydir);
}

static void	calc_dda(t_data *d, t_ray *r)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (r->x.side_dist < r->y.side_dist)
		{
			r->x.side_dist += r->x.delta_dist;
			r->x.map += r->x.step;
			r->side = 1;
		}
		else
		{
			r->y.side_dist += r->y.delta_dist;
			r->y.map += r->y.step;
			r->side = 0;
		}
		if (d->map[r->y.map][r->x.map] > 0)
			hit = 1;
	}
	r->perp_dist = get_perp_dist(d, r);
}

static void	init_dist(t_rvec *v, double pos)
{
	if (v->raydir == 0)
		v->delta_dist = 1e30;
	else
		v->delta_dist = fabs(1 / v->raydir);
	if (v->raydir < 0)
	{
		v->step = -1;
		v->side_dist = (pos - v->map) * v->delta_dist;
	}
	else
	{
		v->step = 1;
		v->side_dist = (v->map + 1 - pos) * v->delta_dist;
	}
}

void	raycasting(t_data *d)
{
	t_ray	r;
	double	camera_x;
	int		x;
	int		line_height;

	ft_memset(&r, 0, sizeof(t_ray));
	x = -1;
	while (++x < WINX)
	{
		camera_x = 2 * x / (double)WINX - 1;
		r.x.raydir = d->v.dir_x + d->v.plane_x * camera_x;
		r.y.raydir = d->v.dir_y + d->v.plane_y * camera_x;
		r.x.map = (int)d->v.pos_x;
		r.y.map = (int)d->v.pos_y;
		init_dist(&r.x, d->v.pos_x);
		init_dist(&r.y, d->v.pos_y);
		calc_dda(d, &r);
		line_height = (int)(WINY / r.perp_dist);
		r.ratio = 1.0 * d->t.tex_hei / line_height;
		draw_wall(d, &r, x, line_height);
	}
}
