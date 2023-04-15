/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:48:58 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/14 17:47:31 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

void	ft_fcase(int (**fc)(int, int))
{
	fc[0] = ft_sum;
	fc[1] = ft_sub;
	fc[2] = ft_mul;
	fc[3] = ft_div;
	fc[4] = ft_mod;
}

int	ft_is_op(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == '*')
		return (2);
	if (c == '/')
		return (3);
	if (c == '%')
		return (4);
	return (-1);
}

int	ft_ck_op(char **str)
{
	int	i;

	i = 0;
	while (str[2][i])
		i++;
	if (i != 1)
		return (1);
	if (ft_is_op(str[2][0]) == -1)
		return (1);
	return (0);
}

int	ft_print_error(int op, int b)
{
	if (op == 3 && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (1);
	}
	if (op == 4 && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	(*fc[5])(int, int);
	int	op;
	int	a;
	int	b;

	if (ac != 4)
		return (0);
	if (ft_ck_op(av))
	{
		write(1, "0\n", 2);
		return (0);
	}
	ft_fcase(fc);
	op = ft_is_op(av[2][0]);
	a = ft_atoi(av[1]);
	b = ft_atoi(av[3]);
	if (ft_print_error(op, b))
		return (0);
	ft_putnbr(fc[op](a, b));
	write(1, "\n", 1);
	return (0);
}
