/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:01:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/04/03 18:11:52 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	show_pid(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "PID = ", 6);
	ft_putnbr_fd((int)pid, 1);
	ft_putchar_fd('\n', 1);
}

void	*ft_realloc(char *str)
{
	char	*res;

	res = NULL;
	if (!ft_strlen(str))
		return (ft_calloc(STR_INCR + 1, sizeof(char)));
	else
	{
		res = ft_calloc (ft_strlen(str) + STR_INCR + 1, sizeof(char));
		ft_strlcpy(res, str, ft_strlen(str));
	}
	if (str)
		free(str);
	return (res);
}

char	*end_msg(int pid, char **str, char *c)
{
	ft_putstr_fd(*str, 1);
	ft_putchar_fd('\n', 1);
	kill(pid, SIGUSR2);
	if (*str)
		free(*str);
	usleep(300);
	*c = 0;
	return (NULL);
}

void	sig_handler_info(int sig, siginfo_t *info, void	*ucontext)
{
	static int	i = 0;
	static char	c = 0;
	static char	*msg = NULL;

	(void)ucontext;
	c |= (sig == SIGUSR2) << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			msg = end_msg(info->si_pid, &msg, &c);
		else
		{
			i = ft_strlen(msg);
			if (i % STR_INCR == 0)
				msg = ft_realloc(msg);
			msg[i] = c;
			c = 0;
		}
		i = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;

	(void)argv;
	if (argc == 1)
	{
		act.sa_sigaction = sig_handler_info;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		show_pid();
		while (1)
			pause();
	}
	return (0);
}
