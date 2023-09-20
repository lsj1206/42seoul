/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:46:40 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/19 14:29:09 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*destroy_thread(t_philo *p, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_join(p[i].thread, NULL);
	return (p);
}

t_shr	*destroy_mutex(t_shr *shr, int num)
{
	int	i;

	pthread_mutex_destroy(&shr->mtx);
	pthread_mutex_destroy(&shr->print);
	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&shr->forks[i]);
	free(shr->forks);
	return (shr);
}

int	exit_process(t_philo *p, int exit_code)
{
	destroy_thread(p, p->shr->init_errno);
	destroy_mutex(p->shr, p->arg->philo_num);
	free(p);
	return (exit_code);
}

int	err_handler(char *err_str, t_shr *shr, t_philo *p)
{
	if (shr)
	{
		if (shr->init_errno <= -3)
			pthread_mutex_destroy(&shr->mtx);
		if (shr->init_errno <= -2)
			pthread_mutex_destroy(&shr->print);
		if (shr->forks && shr->init_errno == -1)
			free(p->shr->forks);
		if (shr->forks)
			destroy_mutex(shr, shr->init_errno);
	}
	if (p)
		free(p);
	printf("\033[31m%s\033[0m\n", err_str);
	return (ERROR);
}
