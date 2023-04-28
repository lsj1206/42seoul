/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:27:51 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:33 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	send_data(int pid, char *str)
{
	int	i;
	int	bit_i;

	i = 0;
	while (1)
	{
		bit_i = 8;
		while (--bit_i > -1)
		{
			usleep(50);
			if (str[i] & (1 << bit_i))
				kill(pid, ONE);
			else
				kill(pid, ZERO);
			pause();
		}
		if (!str[i])
			break ;
		i++;
	}
}

void	receive_ack(int signo, siginfo_t *info, void *context)
{
	static int	ack_cnt = 0;

	ack_cnt++;
	if (signo == ZERO)
	{
		ft_printf("Server pid [%d], ", info->si_pid);
		ft_printf("ACK count : [%d]\n", ack_cnt);
		(void)context;
		ack_cnt = 0;
		exit(0);
	}
}

static int	valid_arg(int ac, char **av)
{
	int		server_pid;
	int		i;

	if (ac != 3 || !ft_strlen(av[2]))
		exit(1);
	i = -1;
	while (av[1][++i])
		if (!ft_isdigit(av[1][i]))
			exit(1);
	server_pid = ft_atoi(av[1]);
	if (server_pid < 100 || server_pid > 99998)
		exit(1);
	return (server_pid);
}

int	main(int ac, char **av)
{
	struct sigaction	respone_sig;
	pid_t				client_pid;
	int					server_pid;
	int					err;

	server_pid = valid_arg(ac, av);
	client_pid = getpid();
	ft_printf("Client pid : [%d]\n", client_pid);
	ft_printf("Send byte : [%d]\n", ft_strlen(av[2]));
	respone_sig.sa_sigaction = receive_ack;
	respone_sig.sa_flags = SA_SIGINFO;
	err = 0;
	err += sigaction(ONE, &respone_sig, 0);
	err += sigaction(ZERO, &respone_sig, 0);
	if (err != 0)
		exit(1);
	send_data(server_pid, av[2]);
	return (0);
}
