/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:54:01 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/09 15:25:20 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PX 64
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_error
{
	int		is_enter;
	int		is_c;
	int		is_e;
	int		is_p;
	int		is_valid;
}			t_err;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_img
{
	void	*pl[4];
	void	*item;
	void	*road;
	void	*wall;
	void	*exit;
}			t_img;

typedef struct s_db
{
	void	*mlx_p;
	void	*win_p;
	char	**map;
	int		**v_arr;
	int		map_w;
	int		map_h;
	int		item_cnt;
	size_t	move_cnt;
	t_err	err;
	t_img	img;
	t_pos	player;
	t_pos	exit;
}			t_db;

t_db	db_init(t_db *db);
void	map_init(t_db *db, int ac, char **av);
void	map_maker(t_db *db, int fd);
char	*map_read(t_db *db, int fd);
void	img_init(t_db *db);
void	img_mapping(t_db *db, int x, int y, int dir);
void	win_printer(t_db *db, int key);
void	pos_init(t_db *db);
int		key_press(int key, t_db *db);
void	move(t_db *db, t_pos pos, int x, int y);
void	move_printer(t_db *db);
void	err_printer(t_db *db, int err_case);
void	err_map_name(t_db *db, int ac, char *str);
void	err_map_data(t_db *db, char **map);
void	err_img_data(t_db *db);
void	err_rectangular(t_db *db, char **map, int x);
void	err_outer_wall(t_db *db, char **map, int x, int y);
void	err_component(t_db *db, int c);
void	err_map_validation(t_db *db);
void	visited_init(t_db *db);
void	dfs(t_db *db, int x, int y);
int		pos_valid(t_db *db, int x, int y);
void	free_all(t_db *db);
void	free_map(t_db *db);
void	free_v_arr(t_db *db);
void	free_mlx(t_db *db);
int		exit_game(t_db *db);

void	*xfti(t_db *db, void *img_p, char *str);
int		pitw(t_db *db, void *img_p, int x, int y);

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(size_t num);
char	**ft_split(char const *s, char c);
#endif
