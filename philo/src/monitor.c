/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:50 by hehuang           #+#    #+#             */
/*   Updated: 2024/06/30 18:59:04 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>

int	check_death(t_process *process)
{
	int		i;
	size_t	time;

	i = -1;
	while (++i < process->ph_nb)
	{
		pthread_mutex_lock(&(process->philos[i]->meal));
		time = process->philos[i]->last_meal;
		pthread_mutex_unlock(&(process->philos[i]->meal));
		if (get_current_time() - time >= \
			(size_t)process->die_in && time != 0)
		{
			display_msg(DEAD, process->philos[i]);
			pthread_mutex_lock(&(process->end_check));
			process->philos[i]->is_dead = 1;
			pthread_mutex_unlock(&(process->end_check));
			return (1);
		}
	}
	return (0);
}

int	all_ate(t_process *process)
{
	int	i;

	i = -1;
	if (process->round == -1)
		return (0);
	while (++i < process->ph_nb)
	{
		pthread_mutex_lock(&(process->philos[i]->meal));
		if (process->philos[i]->meals_eaten >= process->round
			&& !process->philos[i]->finish)
		{
			process->finished++;
			process->philos[i]->finish = 1;
		}
		pthread_mutex_unlock(&(process->philos[i]->meal));
	}
	if (process->finished == process->ph_nb)
	{
		return (1);
	}
	return (0);
}

void	*monitor(void *proc)
{
	t_process	*process;

	process = (t_process *) proc;
	while (1)
	{
		if (check_death(process) || all_ate(process))
		{
			pthread_mutex_lock(&(process->end_check));
			process->end = 1;
			pthread_mutex_unlock(&(process->end_check));
			break ;
		}
	}
	return (process);
}
