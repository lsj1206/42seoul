/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:53:08 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/07 14:24:35 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_swap(char **i, char **j)
{
	char	*temp;

	temp = *i;
	*i = *j;
	*j = temp;
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

void	print_ac(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			write(1, &av[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	j;

	i = (ac - 1);
	while (i)
	{
		j = 1;
		while (j < i)
		{
			if ((ft_strcmp(av[j], av[j + 1])) > 0)
				ft_swap((av + j), (av + j + 1));
			j++;
		}
		i--;
	}
	print_ac(ac, av);
	return (0);
}
