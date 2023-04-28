/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:37:54 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 17:16:28 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int a, int b)
{
	if ((a == 1 || a == x) && (b == 1 || b == y))
		ft_putchar('o');
	else if (a == 1 || a == x)
		ft_putchar('|');
	else if (b == 1 || b == y)
		ft_putchar('-');
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	a;
	int	b;

	b = 1;
	while (b <= y)
	{
		a = 1;
		while (a <= x)
		{
			check(x, y, a, b);
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
