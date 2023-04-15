/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:51:05 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/15 12:47:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	gap;
	int	i;

	i = 0;
	gap = 0;
	while (1)
	{
		if (s1[i] != s2[i])
		{
			gap = s1[i] - s2[i];
			break ;
		}
		if (s1[i] == '\0' && s2[i] == '\0')
			break ;
		i++;
	}
	return (gap);
}

void	ft_sort_string_tab(char **tab)
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
			if (ft_strcmp(*(tab + j), *(tab + j + 1)) > 0)
				ft_swap((tab + j), (tab + j + 1));
			j++;
		}
		i--;
	}
}
