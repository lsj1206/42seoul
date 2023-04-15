/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:16:11 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/14 14:09:26 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sc;

	i = 0;
	sc = 0;
	if (length < 2)
		return (1);
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0 && sc == 0)
			sc = 1;
		else if (f(tab[i], tab[i + 1]) < 0 && sc == 0)
			sc = 2;
		else if (f(tab[i], tab[i + 1]) < 0 && sc == 1)
			return (0);
		else if (f(tab[i], tab[i + 1]) > 0 && sc == 2)
			return (0);
		i++;
	}
	return (1);
}
