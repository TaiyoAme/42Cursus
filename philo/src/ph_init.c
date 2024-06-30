/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:38:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/06/30 18:01:12 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <bits/pthreadtypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

t_philo	*create_philo(int id, t_process *process)
{
	t_philo	*res;

	res = malloc(sizeof(t_philo));
	res->id = id + 1;
	res->is_dead = 0;
	res->is_eating = 0;
	res->last_meal = 0;
	res->is_sleeping = 0;
	res->meals_eaten = 0;
	res->finish = 0;
	res->process = process;
	pthread_mutex_init(&(res->meal), NULL);
	return (res);
}

void	*init_process(int nb, int die_in, int diner_time, int sl_duration)
{
	t_process	*res;

	res = malloc(sizeof(t_process));
	if (!res)
		return (NULL);
	res->ph_nb = nb;
	res->die_in = die_in;
	res->eat_time = diner_time;
	res->sl_duration = sl_duration;
	res->o_dead = 0;
	res->round = -1;
	res->end = 0;
	res->start_time = 0;
	res->finished = 0;
	pthread_mutex_init(&(res->writing), NULL);
	pthread_mutex_init(&(res->end_check), NULL);
	return (res);
}

void	give_forks(t_process *process)
{
	int	i;

	i = -1;
	while (++i < process->ph_nb - 1)
	{
		process->philos[i]->r_fork = &(process->forks[i]);
		process->philos[i]->l_fork = &(process->forks[i + 1]);
	}
	process->philos[i]->r_fork = &(process->forks[i]);
	process->philos[i]->l_fork = &(process->forks[0]);
}

t_process	*init_ph(char *nb, char *die_in, char *eat_t, char *sleep_t)
{
	int				i;
	t_process		*process;

	i = -1;
	process = init_process(ft_atoi(nb), ft_atoi(die_in), \
						ft_atoi(eat_t), ft_atoi(sleep_t));
	if (!process)
		return (NULL);
	process->philos = malloc(atoi(nb) * sizeof(t_philo));
	if (!process->philos)
		return (NULL);
	process->forks = malloc(atoi(nb) * sizeof(pthread_mutex_t));
	if (!process->forks)
		return (NULL);
	while (++i < ft_atoi(nb))
	{
		process->philos[i] = create_philo(i, process);
		pthread_mutex_init(&(process->forks[i]), NULL);
	}
	give_forks(process);
	return (process);
}
