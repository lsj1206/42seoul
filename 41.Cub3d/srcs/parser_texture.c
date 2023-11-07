/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:54:12 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 17:51:16 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	*insert_texture(t_data *d, t_img *t, char *path)
{
	int	*temp;
	int	wid;
	int	hei;
	int	i;

	ft_memset(t, 0, sizeof(t_img));
	t->p = mlx_xpm_file_to_image(d->mlx, path, &wid, &hei);
	if (!t->p)
		err_handler(d, ERR_IMG, 0);
	if (d->t.tex_wid == 0 && d->t.tex_hei == 0)
	{
		d->t.tex_wid = wid;
		d->t.tex_hei = hei;
	}
	if (d->t.tex_wid != wid || d->t.tex_hei != hei)
		err_handler(d, ERR_IMG, 0);
	temp = (int *)malloc(sizeof(int) * (wid * hei));
	if (!temp)
		err_handler(d, ERR_MEM, 0);
	t->addr = (int *)mlx_get_data_addr(t->p, &t->bpp, &t->line, &t->endian);
	i = -1;
	while (++i < (wid * hei))
		temp[i] = t->addr[i];
	mlx_destroy_image(d->mlx, t->p);
	return (temp);
}

void	init_texture(t_data *d)
{
	t_img	tmp;
	int		*temp;
	int		i;

	d->t.tex = int_arr_alloc(4);
	if (!d->t.tex)
		err_handler(d, ERR_MEM, 0);
	i = -1;
	while (++i < 4)
	{
		temp = d->t.tex[i];
		d->t.tex[i] = insert_texture(d, &tmp, d->t.path[i]);
		free(temp);
	}
	sstr_free(d->t.path);
	d->t.path = 0;
}
