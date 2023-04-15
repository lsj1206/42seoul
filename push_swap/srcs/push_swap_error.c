/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:26:03 by seojulee          #+#    #+#             */
/*   Updated: 2023/02/16 12:50:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	error_input(char *str)
{
	int	flag;
	int	i;

	i = -1;
	flag = 0;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			flag = 1;
	}
	if (!flag)
		error_print();
	i = -1;
	while (str[++i])
	{
		if (ft_isdigit(str[i]))
			continue ;
		if (str[i] == ' ')
			continue ;
		if (!i && str[i] == '-')
			continue ;
		error_print();
	}
}

void	error_overlap(int *arr, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
		{
			if (arr[i] == arr[j])
				error_print();
		}
	}
}
