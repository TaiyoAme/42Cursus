/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:59:25 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/08 16:44:59 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>

int	ft_nb_ret_size(const char *nptr)
{
	int					i;
	unsigned long long	res;

	res = 0;
	i = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + nptr[i] - '0';
		i++;
	}
	if (i > 20 || nptr[i] != '\0')
		return (0);
	return (i);
}

int	check_round(t_process *process)
{
	int	i;

	i = -1;
	while (++i < process->ph_nb)
	{
		if (process->philos[i]->meals_eaten != process->round)
			return (0);
		if (process->philos[i]->last_meal - process->die_in < 0)
		{
			process->philos[i]->is_dead = 1;
			return (0);
		}
	}
	return (1);
}

void	ft_puttime_fd(size_t n, int fd)
{
	unsigned long long	nl;
	char				c;

	nl = (unsigned long long)n;
	if (nl >= 10)
		ft_puttime_fd((nl / 10), fd);
	c = (nl % 10) + '0';
	write (fd, &c, 1);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}
