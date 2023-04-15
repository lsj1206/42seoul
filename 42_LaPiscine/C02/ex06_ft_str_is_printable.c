/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:12:40 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/29 19:49:54 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	t_flag;

	t_flag = 1;
	while (*str != '\0')
	{
		if (32 <= *str && *str <= 126)
			t_flag = 1;
		else
			return (0);
		str++;
	}
	return (t_flag);
}
