/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:50:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:46:02 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "define.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

/*parser*/
void		parser(t_data *d, int argc, char **argv);
void		parse_arg(t_data *d, int fd);
int			parse_rgb(t_data *d, char *str);
void		parse_map(t_data *d, int fd);
int			vaild_component(t_data *d, char **map);
int			valid_outerwall(t_data *d, char **map);
void		init_texture(t_data *d);
/*raycasting & draw*/
void		raycasting(t_data *d);
void		draw_background(t_data *d);
void		draw_wall(t_data *d, t_ray *r, int x, int line_height);
void		print_window(t_data *d);
/*event & move*/
int			press_key(int key, t_data *d);
int			move_forward(t_data *d, double speed);
int			move_backward(t_data *d, double speed);
int			move_left(t_data *d, double speed);
int			move_right(t_data *d, double speed);
int			change_view(t_data *d, double speed);
/*utils*/
char		*str_alloc(t_data *d, char *contents);
char		*str_fjoin(t_data *d, char *str1, char *str2);
char		*str_alloc(t_data *d, char *contents);
char		**sstr_alloc(t_data *d, int len);
int			sstr_len(char **sstr);
void		*sstr_free(char **sstr);
int			**int_arr_alloc(int len);
void		*int_arr_free(int **arr, int size);
/*destroy*/
void		err_handler(t_data *d, char *err_str, void *p);
void		*free_texture(t_data *d);
int			free_dfs(t_dfs *dfs, int num);
void		*free_map(t_data *d);
int			exit_process(t_data *d);
#endif
