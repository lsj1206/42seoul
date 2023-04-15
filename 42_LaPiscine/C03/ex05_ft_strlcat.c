/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 12:28:12 by seojulee          #+#    #+#             */
/*   Updated: 2022/09/02 09:13:22 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_take_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;
	unsigned int	d_len;
	unsigned int	s_len;

	i = 0;
	len = 0;
	d_len = ft_take_len(dest);
	s_len = ft_take_len(src);
	while ((d_len + i + 1) < size && src[i] != '\0')
	{
		dest[d_len + i] = src[i];
		i++;
	}
	if (d_len + 1 > size)
		len = s_len + size;
	else
		len = d_len + s_len;
	dest[d_len + i] = '\0';
	return (len);
}
