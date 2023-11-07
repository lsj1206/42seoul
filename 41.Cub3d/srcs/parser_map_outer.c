/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map_outer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:49:08 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 18:02:11 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_valid_map(t_dfs *dfs, int y, int x)
{
	if (y < 0 || x < 0)
		return (ERROR);
	if (y >= dfs->h || x >= dfs->w[y])
		return (ERROR);
	if (dfs->map[y][x] == 32)
		return (ERROR);
	return (SUCCESS);
}

static void	run_dfs(t_dfs *dfs, int y, int x)
{
	const int	dy[4] = {0, 1, -1, 0};
	const int	dx[4] = {1, 0, 0, -1};
	int			i;

	if (dfs->map[y][x] == '1' || dfs->v[y][x] == 1)
		return ;
	if (dfs->error)
		return ;
	dfs->v[y][x] = 1;
	i = -1;
	while (++i < 4)
	{
		if (check_valid_map(dfs, y + dy[i], x + dx[i]))
		{
			dfs->error = 1;
			return ;
		}
		run_dfs(dfs, y + dy[i], x + dx[i]);
	}
}

static int	alloc_dfs(t_dfs *dfs, char **map, int len)
{
	int	i;
	int	width;

	ft_memset((void *)dfs, 0, sizeof(t_dfs));
	dfs->w = (int *)malloc(sizeof(int) * len);
	if (!dfs->w)
		return (-2);
	dfs->v = (int **)malloc(sizeof(int *) * len);
	if (!dfs->v)
		return (-1);
	i = -1;
	while (++i < len)
	{
		width = ft_strlen(map[i]);
		dfs->w[i] = width;
		dfs->v[i] = malloc(sizeof(int) * width);
		if (!dfs->v[i])
			return (i);
	}
	return (len + 1);
}

static int	init(t_dfs *dfs, char **map, int len)
{
	int	errno;
	int	i;
	int	j;

	errno = alloc_dfs(dfs, map, len);
	if (errno != (len + 1))
		return (errno);
	i = 0;
	while (i < len)
	{
		j = -1;
		while (++j < dfs->w[i])
			dfs->v[i][j] = 0;
		i++;
	}
	dfs->map = map;
	dfs->h = len;
	return (errno);
}

int	valid_outerwall(t_data *d, char **map)
{
	int		errno;
	int		i;
	int		j;
	t_dfs	dfs;

	errno = init(&dfs, map, d->map_height);
	if (errno != (d->map_height + 1))
	{
		free_dfs(&dfs, errno);
		err_handler(d, ERR_MEM, sstr_free(map));
	}
	i = -1;
	while (++i < d->map_height)
	{
		j = -1;
		while (++j < dfs.w[i])
			if (map[i][j] == '0' && !dfs.v[i][j])
				run_dfs(&dfs, i, j);
	}
	free_dfs(&dfs, d->map_height);
	if (dfs.error)
		return (ERROR);
	return (SUCCESS);
}
