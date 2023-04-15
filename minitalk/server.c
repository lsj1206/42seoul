/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojulee <seojulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:29:45 by seojulee          #+#    #+#             */
/*   Updated: 2023/03/18 15:45:22 by seojulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_db	g_db;

static int	bit_operation(int binary)
{
	g_db.buf |= binary;
	if (--g_db.bit_cnt)
	{
		g_db.buf <<= 1;
		return (1);
	}
	g_db.bit_cnt = 8;
	if (!g_db.buf)
		return (0);
	ft_printf("%c", g_db.buf);
	g_db.buf = 0;
	return (1);
}

void	server_handler(int signo, siginfo_t *info, void *context)
{
	int		value;

	if (!g_db.client_pid)
		g_db.client_pid = info->si_pid;
	else
		if (g_db.client_pid != info->si_pid)
			return ;
	usleep(50);
	if (signo == ONE)
		value = bit_operation(1);
	else
		value = bit_operation(0);
	if (value)
	{
		kill(info->si_pid, ONE);
		return ;
	}
	ft_printf("\nSent client pid : [%d]\n", info->si_pid);
	kill(info->si_pid, ZERO);
	g_db.client_pid = 0;
	(void)context;
}

static void	init_db(void)
{
	g_db.server_pid = getpid();
	g_db.client_pid = 0;
	g_db.bit_cnt = 8;
	g_db.err_cnt = 0;
	g_db.buf = 0;
}

int	main(void)
{
	struct sigaction	sig;

	init_db();
	ft_printf("Server pid : [%d]\n", g_db.server_pid);
	sig.sa_sigaction = server_handler;
	sig.sa_flags = SA_SIGINFO;
	g_db.err_cnt += sigaction(ONE, &sig, 0);
	g_db.err_cnt += sigaction(ZERO, &sig, 0);
	if (g_db.err_cnt != 0)
		exit(1);
	while (1)
		pause();
	return (0);
}
