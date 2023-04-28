/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:59:17 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/31 13:25:37 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ('A' <= str[i] && str[i] <= 'Z')
			str[i] += 32;
		if ('a' <= str[i] && str[i] <= 'z')
		{
			if (i == 0)
				str[i] -= 32;
			else if (31 > str[i - 1])
				str[i] -= 32;
			else if (32 <= str[i - 1] && str[i - 1] <= 47)
				str[i] -= 32;
			else if (58 <= str[i - 1] && str[i - 1] <= 64)
				str[i] -= 32;
			else if (91 <= str[i - 1] && str[i - 1] <= 96)
				str[i] -= 32;
			else if (123 <= str[i - 1])
				str[i] -= 32;
		}
		i++;
	}
	return (str);
}
