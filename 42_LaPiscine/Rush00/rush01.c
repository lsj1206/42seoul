/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 20:37:34 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 17:16:19 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check(int x, int y, int a, int b)
{
	if ((a == 1 && b == 1) || (a == x && b == y))
		ft_putchar('/');
	else if ((a == x && b == 1) || (a == 1 && b == y))
		ft_putchar('\\');
	else
	{
		if (!(a == 1 || a == x) && !(b == 1 || b == y))
			ft_putchar(' ');
		else
			ft_putchar('*');
	}
}

void	one_line_case(int src, int cnt)
{
	if (cnt == 1)
		ft_putchar('/');
	else if (cnt == src)
		ft_putchar('\\');
	else
		ft_putchar('*');
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
			if (y == 1)
				one_line_case(x, a);
			else if (x == 1)
				one_line_case(y, b);
			else
				check(x, y, a, b);
			a++;
		}
		ft_putchar('\n');
		b++;
	}
}
