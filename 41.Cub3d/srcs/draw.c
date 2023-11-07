/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:50:07 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 17:58:47 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_window(t_data *d)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	y = -1;
	while (++y < WINY)
	{
		x = -1;
		while (++x < WINX)
			d->t.sc.addr[++i] = d->buf[y][x];
	}
	mlx_put_image_to_window(d->mlx, d->win, d->t.sc.p, 0, 0);
}

static int	get_texture(t_data *d, t_ray *r, int tex_x, int tex_y)
{
	int	pos;

	pos = d->t.tex_hei * tex_y + tex_x;
	if (r->side && r->x.raydir > 0)
		return (d->t.tex[0][pos]);
	else if (r->side && r->x.raydir < 0)
		return (d->t.tex[1][pos]);
	else if (!r->side && r->y.raydir > 0)
		return (d->t.tex[2][pos]);
	else if (!r->side && r->y.raydir < 0)
		return (d->t.tex[3][pos]);
	return (0);
}

static int	get_texture_x(t_data *d, t_ray *r)
{
	double	wall;
	int		tex_x;

	if (r->side)
		wall = d->v.pos_y + r->perp_dist * r->y.raydir;
	else
		wall = d->v.pos_x + r->perp_dist * r->x.raydir;
	wall -= floor(wall);
	tex_x = (int)(wall * (double)d->t.tex_wid);
	if (r->side == 1 && r->x.raydir > 0)
		tex_x = d->t.tex_wid - tex_x - 1;
	if (r->side == 0 && r->y.raydir < 0)
		tex_x = d->t.tex_wid - tex_x - 1;
	return (tex_x);
}

void	draw_wall(t_data *d, t_ray *r, int x, int line_height)
{
	double	tex_p;
	int		tex_x;
	int		tex_y;
	int		end_y;
	int		y;

	y = -line_height / 2 + WINY / 2;
	if (y < 0)
		y = 0;
	end_y = line_height / 2 + WINY / 2;
	if (end_y >= WINY)
		end_y = WINY - 1;
	tex_x = get_texture_x(d, r);
	tex_p = (y - WINY / 2 + line_height / 2) * r->ratio;
	while (y < end_y)
	{
		tex_y = (int)tex_p & (d->t.tex_hei - 1);
		tex_p += r->ratio;
		d->buf[y][x] = get_texture(d, r, tex_x, tex_y);
		y++;
	}
}

void	draw_background(t_data *d)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (WINY / 2))
	{
		x = -1;
		while (++x < WINX)
		{
			d->buf[y][x] = d->t.celling;
			d->buf[(WINY - 1) - y][x] = d->t.floor;
		}
	}
}
