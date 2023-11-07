/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:30:14 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:42:58 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	init_vector(t_data *d)
{
	d->v.pos_x += 0.5;
	d->v.pos_y += 0.5;
	if (d->dir == 1)
		d->v.dir_y = 1.00;
	else if (d->dir == 2)
		d->v.dir_y = -1.00;
	else if (d->dir == 3)
		d->v.dir_x = 1.00;
	else if (d->dir == 4)
		d->v.dir_x = -1.00;
	if (d->v.dir_x != 0.00)
		d->v.plane_y = 0.66;
	else
		d->v.plane_x = 0.66;
}

static void	init_window(t_data *d)
{
	int	bpp;
	int	line;
	int	endian;

	d->mlx = mlx_init();
	if (!d->mlx)
		err_handler(d, ERR_MLX, 0);
	d->win = mlx_new_window(d->mlx, WINX, WINY, NAME);
	if (!d->win)
		err_handler(d, ERR_MLX, 0);
	d->t.sc.p = mlx_new_image(d->mlx, WINX, WINY);
	if (!d->t.sc.p)
		err_handler(d, ERR_MLX, 0);
	d->t.sc.addr = (int *)mlx_get_data_addr(d->t.sc.p, &bpp, &line, &endian);
	d->t.sc.endian = endian;
	d->t.sc.line = line;
	d->t.sc.bpp = bpp;
}

void	parser(t_data *d, int argc, char **argv)
{
	int		fd;
	char	*temp;

	if (argc != 2)
		err_handler(d, "Error\nDetails : File not found", 0);
	if (WINX < 100 || WINY < 100)
		err_handler(d, "Error\nDetails : Window size too small", 0);
	temp = ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]));
	if (!temp || ft_strlen(temp) > 4)
		err_handler(d, "Error\nDetails : Invalid file", 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		err_handler(d, "Error\nDetails : Failed to open file", 0);
	parse_arg(d, fd);
	parse_map(d, fd);
	close(fd);
	init_vector(d);
	init_window(d);
	init_texture(d);
}
