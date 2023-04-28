/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:18:59 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/06 15:48:47 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_arr(char *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &arr[i], 1);
		i++;
	}
	if (arr[0] != ((10 - n) + '0'))
		write(1, ", ", 2);
}

void	rec(int depth, int st, int n, char *arr)
{
	if (depth == n)
	{
		print_arr(arr, n);
		return ;
	}
	while (st < 10)
	{
		arr[depth] = st + '0';
		rec(depth + 1, st + 1, n, arr);
		st++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	arr[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		arr[i] = '0';
		i++;
	}
	rec(0, 0, n, arr);
}
