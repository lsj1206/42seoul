/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:30:03 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:28 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <unistd.h>

# define ONE SIGUSR1
# define ZERO SIGUSR2

typedef struct s_db
{
	pid_t			server_pid;
	int				client_pid;
	int				bit_cnt;
	int				err_cnt;
	unsigned char	buf;

}					t_db;
/*server*/
void		server_handler(int signo, siginfo_t *info, void *context);
/*client*/
void		receive_ack(int signo, siginfo_t *info, void *context);
/*utils*/
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
long long	ft_atoi(const char *str);

#endif
