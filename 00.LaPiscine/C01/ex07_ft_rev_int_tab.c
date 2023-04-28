/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:19:15 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/29 08:42:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	hf_size;
	int	cnt;
	int	tmp;

	hf_size = size / 2;
	cnt = 0;
	while (cnt < hf_size)
	{
		tmp = 0;
		tmp = tab[cnt];
		tab[cnt] = tab[(size - 1) - cnt];
		tab[(size - 1) - cnt] = tmp;
		cnt++;
	}
}
