/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyyang <juyyang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:34:03 by juyyang           #+#    #+#             */
/*   Updated: 2022/09/04 22:34:00 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<unistd.h>

int		validation(int **arr, int n, int *view);
void	solution(int **arr, int n, int *view);
void	show_error(int n);

void	zeros(int **arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	to_int_arr(char *str, int *view)
{
	int	cnt;
	int	i;

	i = 0;
	cnt = 0;
	while (i < 31)
	{
		if (str[i] >= '0' && str[i] <= '9')
			view[cnt++] = str[i] - '0';
		i++;
	}
	return (cnt);
}

void	print_matrix(int **arr, int *view)
{
	int		i;
	int		j;
	char	buff[2];

	if (validation(arr, 4, view))
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				buff[0] = arr[i][j] + '0';
				buff[1] = ' ';
				write(1, &buff, 2);
				j++;
			}
			write(1, "\n", 1);
			i++;
		}
	}
	else
		show_error(2);
}

int	main(int ac, char *args[])
{
	int	i;
	int	**arr;
	int	view[16];

	if (ac == 1)
	{
		show_error(1);
		return (0);
	}
	else if (to_int_arr(args[1], view) != 16)
	{
		show_error(1);
		return (0);
	}
	i = 0;
	arr = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
		arr[i++] = (int *)malloc(sizeof(int) * 4);
	zeros(arr, 4);
	solution(arr, 4, view);
	print_matrix(arr, view);
}
