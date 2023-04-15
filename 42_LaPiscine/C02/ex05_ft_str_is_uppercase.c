/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:05:37 by seojulee          #+#    #+#             */
/*   Updated: 2022/08/28 13:11:30 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_str_is_uppercase(char *str)
{
	int	t_flag;

	t_flag = 1;
	while (*str != '\0')
	{
		if ('A' <= *str && *str <= 'Z')
			t_flag = 1;
		else
			return (0);
		str++;
	}
	return (t_flag);
}
