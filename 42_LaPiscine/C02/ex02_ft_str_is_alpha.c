/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 10:16:59 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 12:41:07 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int	t_flag;

	t_flag = 1;
	while (*str != '\0')
	{
		if (('a' <= *str && *str <= 'z') || ('A' <= *str && *str <= 'Z'))
			t_flag = 1;
		else
			return (0);
		str++;
	}
	return (t_flag);
}
