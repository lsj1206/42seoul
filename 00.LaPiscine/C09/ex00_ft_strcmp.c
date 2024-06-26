/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:17:44 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/02 08:38:18 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
