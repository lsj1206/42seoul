/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 21:21:19 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/07 16:11:27 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long long	n;

	n = 2;
	if (nb < 2)
		return (0);
	while ((n * n) <= nb)
	{
		if (nb % n == 0)
			return (0);
		n++;
	}
	return (1);
}
