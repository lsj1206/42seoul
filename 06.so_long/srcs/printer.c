/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:30:09 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/07 17:28:01 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_printer(t_db *db)
{
	char	*cnt;

	cnt = ft_itoa(db->move_cnt);
	write(1, cnt, ft_strlen(cnt));
	write(1, "\n", 1);
	free(cnt);
	return ;
}

int	exit_game(t_db *db)
{
	free_all(db);
	exit(0);
	return (0);
}

void	err_printer(t_db *db, int err_case)
{
	free_all(db);
	write(2, "Error\n", 6);
	if (err_case == 1)
		write(2, "Memory Allocation Failed\n", 26);
	if (err_case == 2)
		write(2, "Fail Init Texture\n", 19);
	if (err_case == 3)
		write(2, "Map File Not Standard\n", 23);
	if (err_case == 4)
		write(2, "Need One Map File\n", 19);
	if (err_case == 5)
		write(2, "Fail Open File\n", 16);
	exit(1);
}
