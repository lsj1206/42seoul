/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:45:18 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/19 14:33:55 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printer(t_philo *p, char *message)
{
	long long	time;

	pthread_mutex_lock(&p->shr->print);
	if (p->shr->is_dead && ft_strcmp(message, DIE))
	{
		pthread_mutex_unlock(&p->shr->print);
		return ;
	}
	time = get_time() - p->shr->start_time;
	printf("%-7lld %-3d%s\n", time, p->id + 1, message);
	pthread_mutex_unlock(&p->shr->print);
}

static int	dead_handler(t_philo *p, int id)
{
	pthread_mutex_lock(&p->shr->print);
	p->shr->is_dead = 1;
	pthread_mutex_unlock(&p->shr->print);
	pthread_mutex_unlock(&p->shr->mtx);
	if (id != -1)
		printer(&p[id], DIE);
	return (END);
}

int	monitor(t_philo *p)
{
	long long	now;
	int			i;

	if (p->arg->must_eat != -1)
	{
		pthread_mutex_lock(&p->shr->mtx);
		if (p->shr->ate_all == p->arg->philo_num)
			return (dead_handler(p, -1));
		pthread_mutex_unlock(&p->shr->mtx);
	}
	i = -1;
	while (++i < p->arg->philo_num)
	{
		pthread_mutex_lock(&p->shr->mtx);
		now = get_time();
		if (!p[i].eating && (now - p[i].ate_time) >= p->arg->time_to_die)
			return (dead_handler(p, i));
		pthread_mutex_unlock(&p->shr->mtx);
	}
	return (CONTINUE);
}

int	start_philo(t_philo *p)
{
	int	i;

	p->shr->start_time = get_time();
	i = -1;
	while (++i < p->arg->philo_num)
	{
		p->shr->init_errno = i;
		p[i].ate_time = get_time();
		if (pthread_create(&p[i].thread, NULL, &routine, &p[i]))
			return (ERROR);
		usleep(10);
	}
	p->shr->init_errno = p->arg->philo_num;
	while (1)
	{
		if (monitor(p))
			break ;
		usleep(1000);
	}
	return (SUCCESS);
}
