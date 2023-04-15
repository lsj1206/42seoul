/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:51:50 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/15 12:48:31 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
		i++;
	i--;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			if (cmp(*(tab + j), *(tab + j + 1)) > 0)
				ft_swap((tab + j), (tab + j + 1));
			j++;
		}
		i--;
	}
}
