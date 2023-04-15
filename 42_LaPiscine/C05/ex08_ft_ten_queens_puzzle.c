/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:07:50 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/07 10:52:14 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_diagonal(int row, int row2, int *board)
{
	if ((row - (row2)) == -(board[row] - board[row2]))
		return (0);
	else
		return (1);
}

int	ft_promise(int row, int *board)
{
	int	col;

	col = 0;
	while (col < row)
	{
		if (board[row] == board[col])
		col++;
	}
}

void	ft_rec_queens(int row, int *board)
{
	int	col;

	col = 0;
	if (row == 10)
	{
		return ;
	}
	while (col < 10)
	{
		board[row] = col;
		if (promise(row, row + 1, board))
			ft_rec_queens(row + 1, board);
		col++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	pos;
	int	i;

	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	pos = ft_rec_queens(0, board);
	return (pos);
}
