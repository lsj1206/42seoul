/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:45:31 by seojulee          #+#    #+#             */
/*   Updated: 2023/09/20 14:46:29 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define SUCCESS	0
# define ERROR		1
# define CONTINUE	0
# define END		1

# define ERR_ARG	"Error : Argument"
# define TAKE_FORK	" has taken a fork"
# define EAT		"\033[35m is eating\033[0m"
# define SLEEP		" is sleeping"
# define THINK		" is thinking"
# define DIE		"\033[31m died\033[0m"

typedef struct s_arg
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
}	t_arg;

typedef struct s_shr
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	mtx;
	long long		start_time;
	int				ate_all;
	int				is_dead;
	int				init_errno;
}	t_shr;

typedef struct s_philo
{
	pthread_t	thread;
	long long	ate_time;
	int			id;
	int			l_fork;
	int			r_fork;
	int			eat_cnt;
	int			eating;
	t_arg		*arg;
	t_shr		*shr;
}	t_philo;

/*routine*/
void		eat(t_philo *p);
int			finish_checker(t_philo *p);
int			routine_handler(t_philo *p);
void		*routine(void *ptr);
/*philo*/
void		printer(t_philo *p, char *message);
int			monitor(t_philo *p);
int			start_philo(t_philo *p);
/*utils*/
long long	get_time(void);
void		timer(t_philo *p, int req_time, int delay_num);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
/*destroy*/
t_philo		*destroy_thread(t_philo *p, int num);
t_shr		*destroy_mutex(t_shr *shr, int num);
int			exit_process(t_philo *p, int exit_code);
int			err_handler(char *err_str, t_shr *shr, t_philo *p);

#endif
