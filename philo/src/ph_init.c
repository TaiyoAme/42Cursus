/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 18:38:48 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/14 17:38:43 by hehuang          ###   ########.fr       */
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
	res->id = id;
	res->is_dead = 0;
	res->is_eating = 0;
	res->last_meal = 0;
	res->is_sleeping = 0;
	res->meals_eaten = 0;
	res->process = process;
	return (res);
}

void	*init_process(int nb, int die_in, int diner_time, int sl_duration)
{
	t_process	*res;
	int			i;

	res = malloc(sizeof(t_process));
	if (!res)
		return (NULL);
	res->ph_nb = nb;
	res->die_in = die_in;
	res->eat_time = diner_time;
	res->sl_duration = sl_duration;
	res->o_dead = 0;
	res->round = -1;
	res->start_time = 0;
	res->finished = 0;
	i = pthread_mutex_init(&(res->writing), NULL);
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
	process->ready = 0;
	give_forks(process);
	return (process);
}
