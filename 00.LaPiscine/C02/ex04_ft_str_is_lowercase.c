/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:54:12 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 12:56:02 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	t_flag;

	t_flag = 1;
	while (*str != '\0')
	{
		if ('a' <= *str && *str <= 'z')
			t_flag = 1;
		else
			return (0);
		str++;
	}
	return (t_flag);
}
