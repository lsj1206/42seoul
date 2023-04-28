/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 21:14:36 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/02 08:50:27 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_get_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	tf_len;
	unsigned int	i;

	tf_len = 0;
	i = 0;
	if (*to_find == '\0')
		return (str);
	tf_len = ft_get_len(to_find);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			i = 0;
			while (i <= tf_len)
			{
				if (to_find[i] == '\0')
					return (str);
				if (*(str + i) != to_find[i])
					break ;
				i++;
			}
		}
		str++;
	}
	return (0);
}
