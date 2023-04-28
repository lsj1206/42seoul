/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:19:57 by juyyang           #+#    #+#             */
/*   Updated: 2022/09/04 22:33:44 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>

int	view_cnt(int **arr, int n, int std, int direction);

int	check(int x, int y, int n, int **arr)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[x][i] == arr[x][y] && y != i)
			return (0);
		else if (arr[i][y] == arr[x][y] && x != i)
			return (0);
		i++;
	}
	return (1);
}

int	validation(int **arr, int n, int *view)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (view_cnt(arr, n, i, 1) != view[4 * 2 + i])
			return (0);
		else if (view_cnt(arr, n, i, 3) != view[4 * 3 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (view_cnt(arr, n, i, 2) != view[i])
			return (0);
		else if (view_cnt(arr, n, i, 4) != view[4 + i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

void	show_error(int case_id)
{
	if (case_id == 1)
	{
		write(1, "Input Error, Try Again", ft_strlen("Unexpected Error\n"));
		write(1, "\n", 1);
	}
	else if (case_id == 2)
	{
		write(1, "Wrong Answer", ft_strlen("Wrong Answer\n"));
		write(1, "\n", 1);
	}
	else
	{
		write(1, "Unexpected Error", ft_strlen("Unexpected Error\n"));
		write(1, "\n", 1);
	}
}
