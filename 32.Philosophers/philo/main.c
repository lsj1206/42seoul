/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:48:12 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/19 14:35:05 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*init_philo(t_arg *arg, t_shr *shr)
{
	t_philo	*p;
	int		i;

	p = (t_philo *)malloc(sizeof(t_philo) * arg->philo_num);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < arg->philo_num)
	{
		p[i].id = i;
		p[i].l_fork = i;
		p[i].r_fork = (i + 1) % arg->philo_num;
		p[i].eat_cnt = 0;
		p[i].ate_time = 0;
		p[i].eating = 0;
		p[i].arg = arg;
		p[i].shr = shr;
	}
	return (p);
}

int	init_shared(t_shr *shr, int num)
{
	shr->start_time = 0;
	shr->ate_all = 0;
	shr->is_dead = 0;
	shr->init_errno = -3;
	if (pthread_mutex_init(&shr->mtx, NULL))
		return (ERROR);
	shr->init_errno = -2;
	if (pthread_mutex_init(&shr->print, NULL))
		return (ERROR);
	shr->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (!shr->forks)
		return (ERROR);
	shr->init_errno = -1;
	while (++shr->init_errno < num)
		if (pthread_mutex_init(&shr->forks[shr->init_errno], NULL))
			return (ERROR);
	return (SUCCESS);
}

int	init_arg(t_arg *arg, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (ERROR);
	arg->philo_num = ft_atoi(av[1]);
	arg->time_to_die = ft_atoi(av[2]);
	arg->time_to_eat = ft_atoi(av[3]);
	arg->time_to_sleep = ft_atoi(av[4]);
	if (arg->philo_num < 1 || arg->time_to_die < 1 \
	|| arg->time_to_eat < 1 || arg->time_to_sleep < 1)
		return (ERROR);
	arg->must_eat = -1;
	if (ac == 6)
	{
		arg->must_eat = ft_atoi(av[5]);
		if (arg->must_eat < 1)
			return (ERROR);
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_arg	arg;
	t_shr	shr;
	t_philo	*p;

	if (init_arg(memset(&arg, 0, sizeof(t_arg)), ac, av))
		return (err_handler(ERR_ARG, 0, 0));
	if (init_shared(&shr, arg.philo_num))
		return (err_handler(ERR_ARG, &shr, 0));
	p = init_philo(&arg, &shr);
	if (!p)
		return (err_handler(ERR_ARG, &shr, p));
	if (start_philo(p))
		return (exit_process(p, ERROR));
	return (exit_process(p, SUCCESS));
}
