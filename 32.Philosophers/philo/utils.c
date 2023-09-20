/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:46:49 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/20 14:47:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) < 0)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	timer(t_philo *p, int req_time, int delay_num)
{
	long long	start_time;
	long long	now;
	int			delay;

	delay = 100 + delay_num;
	start_time = get_time();
	while (1)
	{
		if (finish_checker(p))
			break ;
		now = get_time();
		if ((now - start_time) >= (long long)req_time)
			break ;
		usleep(delay);
	}
}

int	ft_atoi(const char *str)
{
	long long	value;
	long long	temp;

	value = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			temp = value;
			value = (value * 10) + (*str - '0');
			if (temp > value)
				return (0);
			str++;
		}
		else
			return (0);
	}
	return (value);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else
		return (1);
}
