/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:55:26 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/12 18:14:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "minitalk.h"

char	*g_msg;

void	send_bit(int pid, int *pos, int *i)
{
	int	pid_bool;

	pid_bool = 0;
	if ((g_msg[*pos] >> *i) & 1)
		pid_bool = kill(pid, SIGUSR2);
	else
		pid_bool = kill(pid, SIGUSR1);
	if (pid_bool == -1)
	{
		write (1, "Error : wrong PID\n", 18);
		exit(0);
	}
	(*i)++;
	if (*i == 8)
	{
		*i = 0;
		(*pos)++;
	}
}

void	sig_handler_info(int sig, siginfo_t *info, void	*ucontext)
{
	static int	i = 0;
	static int	j = 1;

	(void)ucontext;
	if (sig == SIGUSR2)
	{
		write(1, "----------------------\n", 23);
		write(1, "| Message received ! |\n", 23);
		write(1, "----------------------\n", 23);
		exit(0);
	}
	else if (sig == SIGUSR1)
	{
		send_bit(info->si_pid, &i, &j);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					i;

	if (argc == 3 && ft_strlen(argv[1]) > 0)
	{
		g_msg = argv[2];
		i = 0;
		act.sa_sigaction = sig_handler_info;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		send_bit(ft_atoi(argv[1]), &i, &i);
		while (1)
			pause();
	}
	else
		write(1, "Error : expected a PID and a string only\n", 41);
	return (0);
}
