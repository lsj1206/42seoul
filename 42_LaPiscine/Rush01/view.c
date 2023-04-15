/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:25:27 by juyyang           #+#    #+#             */
/*   Updated: 2022/09/04 22:23:04 by juyyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	view_cnt_row(int **arr, int n, int std)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	cnt = 0;
	max = 0;
	while (i < n)
	{
		if (max < arr[std][i])
		{
			max = arr[std][i];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	view_cnt_row_rev(int **arr, int n, int std)
{
	int	i;
	int	max;
	int	cnt;

	i = n - 1;
	cnt = 0;
	max = 0;
	while (i >= 0)
	{
		if (max < arr[std][i])
		{
			max = arr[std][i];
			cnt++;
		}
		i--;
	}
	return (cnt);
}

int	view_cnt_col(int **arr, int n, int std)
{
	int	i;
	int	max;
	int	cnt;

	i = 0;
	cnt = 0;
	max = 0;
	while (i < n)
	{
		if (max < arr[i][std])
		{
			max = arr[i][std];
			cnt++;
		}
		i++;
	}
	return (cnt);
}

int	view_cnt_col_rev(int **arr, int n, int std)
{
	int	i;
	int	max;
	int	cnt;

	i = n - 1;
	cnt = 0;
	max = 0;
	while (i >= 0)
	{
		if (max < arr[i][std])
		{
			max = arr[i][std];
			cnt++;
		}
		i--;
	}
	return (cnt);
}

int	view_cnt(int **arr, int n, int std, int direction)
{
	int	cnt;

	cnt = 0;
	if (direction == 1)
		cnt = view_cnt_row(arr, n, std);
	else if (direction == 2)
		cnt = view_cnt_col(arr, n, std);
	else if (direction == 3)
		cnt = view_cnt_row_rev(arr, n, std);
	else if (direction == 4)
		cnt = view_cnt_col_rev(arr, n, std);
	return (cnt);
}
