/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:52:44 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/20 14:47:41 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *p)
{
	pthread_mutex_lock(&p->shr->forks[p->l_fork]);
	printer(p, TAKE_FORK);
	pthread_mutex_lock(&p->shr->forks[p->r_fork]);
	printer(p, TAKE_FORK);
	printer(p, EAT);
	pthread_mutex_lock(&p->shr->mtx);
	p->eating = 1;
	p->ate_time = get_time();
	pthread_mutex_unlock(&p->shr->mtx);
	timer(0, p->arg->time_to_eat, p->arg->philo_num);
	pthread_mutex_lock(&p->shr->mtx);
	p->eating = 0;
	pthread_mutex_unlock(&p->shr->mtx);
	pthread_mutex_unlock(&p->shr->forks[p->r_fork]);
	pthread_mutex_unlock(&p->shr->forks[p->l_fork]);
	p->eat_cnt++;
	if (p->eat_cnt == p->arg->must_eat)
	{
		pthread_mutex_lock(&p->shr->mtx);
		p->shr->ate_all++;
		pthread_mutex_unlock(&p->shr->mtx);
	}
}

int	routine_handler(t_philo *p)
{
	if (p->arg->philo_num == 1)
	{
		pthread_mutex_lock(&p->shr->forks[p->l_fork]);
		printer(p, TAKE_FORK);
		timer(p, p->arg->time_to_die, 1);
		pthread_mutex_unlock(&p->shr->forks[p->l_fork]);
		return (END);
	}
	if (p->id % 2)
		timer(p, (p->arg->time_to_eat - 30), p->arg->philo_num);
	return (CONTINUE);
}

int	finish_checker(t_philo *p)
{
	if (!p)
		return (CONTINUE);
	pthread_mutex_lock(&p->shr->mtx);
	if (p->shr->is_dead)
	{
		pthread_mutex_unlock(&p->shr->mtx);
		return (END);
	}
	pthread_mutex_unlock(&p->shr->mtx);
	return (CONTINUE);
}

void	*routine(void *ptr)
{
	t_philo	*p;
	int		delay;

	p = (t_philo *)ptr;
	delay = 10 + p->arg->philo_num;
	if (routine_handler(p))
		return (NULL);
	while (1)
	{
		if (finish_checker(p))
			break ;
		eat(p);
		printer(p, SLEEP);
		timer(p, p->arg->time_to_sleep, p->arg->philo_num);
		printer(p, THINK);
		usleep(delay);
	}
	return (NULL);
}
