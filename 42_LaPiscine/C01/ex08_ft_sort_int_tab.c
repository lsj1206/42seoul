/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 19:50:46 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 21:45:47 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	cnt;
	int	tmp;

	while (size != 0)
	{
		cnt = 0;
		while (cnt <= (size - 2))
		{
			if (tab[cnt] >= tab[cnt + 1])
			{
				tmp = 0;
				tmp = tab[cnt];
				tab[cnt] = tab[cnt + 1];
				tab[cnt + 1] = tmp;
			}
			cnt++;
		}
		size--;
	}
}
