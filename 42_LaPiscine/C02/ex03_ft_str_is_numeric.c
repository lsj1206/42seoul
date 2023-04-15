/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 12:42:08 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 12:43:00 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	t_flag;

	t_flag = 1;
	while (*str != '\0')
	{
		if ('0' <= *str && *str <= '9')
			t_flag = 1;
		else
			return (0);
		str++;
	}
	return (t_flag);
}
