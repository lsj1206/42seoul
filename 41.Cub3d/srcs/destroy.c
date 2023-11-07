/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:44:09 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 18:08:59 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_process(t_data *d)
{
	free_texture(d);
	free_map(d);
	mlx_destroy_image(d->mlx, d->t.sc.p);
	mlx_destroy_window(d->mlx, d->win);
	exit(0);
	return (0);
}

int	free_dfs(t_dfs *dfs, int num)
{
	if (num == -2)
		return (1);
	if (num >= -1)
		free(dfs->w);
	if (num == 0)
	{
		free(dfs->v);
		return (1);
	}
	if (num > 0)
		int_arr_free(dfs->v, num);
	return (1);
}

void	*free_texture(t_data *d)
{
	int	i;

	if (!d->t.tex)
		return (0);
	i = -1;
	while (++i < 4)
	{
		if (d->t.tex[i])
			free(d->t.tex[i]);
	}
	free(d->t.tex);
	d->t.tex = 0;
	return (0);
}

void	*free_map(t_data *d)
{
	int	i;

	if (!d->map)
		return (0);
	i = d->map_height;
	while (--i > -1)
		free(d->map[i]);
	free(d->map);
	d->map = 0;
	return (0);
}

void	err_handler(t_data *d, char *err_str, void *p)
{
	if (p)
		free(p);
	sstr_free(d->t.path);
	free_texture(d);
	free_map(d);
	if (d->t.sc.p)
		mlx_destroy_image(d->mlx, d->t.sc.p);
	if (d->win)
		mlx_destroy_window(d->mlx, d->win);
	printf("\033[31m%s\033[0m\n", err_str);
	exit(1);
}
