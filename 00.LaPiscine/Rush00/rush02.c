/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:37:08 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 17:07:49 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int a, int b)
{
	if (b == 1 && (a == 1 || a == x))
		ft_putchar('A');
	else if (b == y && (a == 1 || a == x))
		ft_putchar('C');
	else
	{
		if (!(a == 1 || a == x) && !(b == 1 || b == y))
			ft_putchar(' ');
		else
			ft_putchar('B');
	}
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
