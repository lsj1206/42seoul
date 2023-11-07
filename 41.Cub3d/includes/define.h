/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 16:36:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/03 17:46:28 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define NAME "cub3D"
# define WINX 1280
# define WINY 720

# define SUCCESS 0
# define ERROR 1

# define KEY_PRESS 2
# define BTN_X 17
# include "key_linux.h"

# define ERR_MEM "Error\nDetails : Allocation"
# define ERR_IMG "Error\nDetails : Texture"
# define ERR_ARG "Error\nDetails : Argument"
# define ERR_MAP "Error\nDetails : Map"
# define ERR_MLX "Error\nDetails : MLX"

typedef struct s_ray_vector
{
	int		map;
	int		step;
	double	raydir;
	double	side_dist;
	double	delta_dist;
}			t_rvec;

typedef struct s_ray
{
	t_rvec	x;
	t_rvec	y;
	int		side;
	double	perp_dist;
	double	ratio;
}			t_ray;

typedef struct s_vector
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}			t_vec;

typedef struct s_dfs
{
	int		y;
	int		x;
	int		h;
	int		*w;
	int		**v;
	int		error;
	char	**map;
}			t_dfs;

typedef struct s_img
{
	void	*p;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
}			t_img;

typedef struct s_texture
{
	char	**path;
	int		**tex;
	int		tex_wid;
	int		tex_hei;
	int		celling;
	int		floor;
	t_img	sc;
}			t_tex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		**map;
	int		buf[WINY][WINX];
	int		map_height;
	int		dir;
	t_tex	t;
	t_vec	v;
}			t_data;

#endif
