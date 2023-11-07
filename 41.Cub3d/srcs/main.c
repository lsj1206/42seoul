/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:53:27 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 17:58:10 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	main_loop(t_data *d)
{
	draw_background(d);
	raycasting(d);
	print_window(d);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	d;

	parser(ft_memset(&d, 0, sizeof(t_data)), argc, argv);
	mlx_hook(d.win, BTN_X, 0, &exit_process, &d);
	mlx_hook(d.win, KEY_PRESS, 1, &press_key, &d);
	mlx_loop_hook(d.mlx, &main_loop, &d);
	mlx_loop(d.mlx);
	return (0);
}
