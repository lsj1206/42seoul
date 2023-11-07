/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:17:20 by seojulee          #+#    #+#             */
/*   Updated: 2023/11/01 18:05:00 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	**int_arr_alloc(int len)
{
	int	**arr;
	int	i;

	arr = (int **)malloc(sizeof(int *) * len);
	if (!arr)
		return (0);
	i = -1;
	while (++i < len)
	{
		arr[i] = (int *)malloc(sizeof(int) * 1);
		if (!arr[i])
			return (int_arr_free(arr, i));
	}
	return (arr);
}

void	*int_arr_free(int **arr, int size)
{
	int	i;

	if (!arr)
		return (0);
	if (!size)
	{
		free(arr);
		return (0);
	}
	i = -1;
	while (++i < size)
		free(arr[i]);
	free(arr);
	return (0);
}
