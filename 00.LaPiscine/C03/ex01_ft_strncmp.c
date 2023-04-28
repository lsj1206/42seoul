/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:37:21 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/02 09:23:14 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				gap;

	i = 0;
	gap = 0;
	while (i < n)
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
