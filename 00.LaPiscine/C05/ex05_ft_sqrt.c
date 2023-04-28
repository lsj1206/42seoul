/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:10:27 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/06 10:01:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long long	n;

	if (nb <= 0)
		return (0);
	if (nb % 2 == 0)
	{
		n = 2;
		while ((n * n) <= nb)
		{
			if ((n * n) == nb)
				return (n);
			n += 2;
		}
	}
	else
	{
		n = 1;
		while ((n * n) <= nb)
		{
			if ((n * n) == nb)
				return (n);
			n += 2;
		}
	}
	return (0);
}
