/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 04:52:09 by juyyang           #+#    #+#             */
/*   Updated: 2022/09/04 22:33:55 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>

int	validation(int **arr, int n, int *view);
int	view_cnt(int **arr, int n, int std, int direction);
int	check(int x, int y, int n, int **arr);

int	dfs(int idx, int **arr, int blank[16][2], int *view)
{
	int	i;
	int	x;
	int	y;

	x = blank[idx][0];
	y = blank[idx][1];
	if (idx == 4 * 4)
		return (validation(arr, 4, view));
	i = 0;
	while (++i <= 4)
	{
		arr[x][y] = i;
		if (view_cnt(arr, 4, x, 1) > view[4 * 2 + x]
			|| view_cnt(arr, 4, y, 2) > view[y])
			return (arr[x][y] = 0);
		if (check(x, y, 4, arr))
		{
			arr[x][y] = i;
			if (dfs(idx + 1, arr, blank, view))
				return (1);
		}
	}
	arr[x][y] = 0;
	return (0);
}

void	solution(int **arr, int n, int *view)
{
	int	i;
	int	j;
	int	cnt;
	int	blank[16][2];

	i = 0;
	cnt = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (arr[i][j] == 0)
			{
				blank[cnt][0] = i;
				blank[cnt][1] = j;
				cnt++;
			}
			j++;
		}
		i++;
	}
	dfs(0, arr, blank, view);
}
