/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:13:06 by hehuang           #+#    #+#             */
/*   Updated: 2024/06/17 18:21:39 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	check_end(t_process *process)
{
	int	i;

	pthread_mutex_lock(&(process->end_check));
	i = process->end;
	pthread_mutex_unlock(&(process->end_check));
	return (i);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	display_msg(L_FORK, philo);
	pthread_mutex_lock(philo->r_fork);
	display_msg(R_FORK, philo);
	display_msg(EATING, philo);
	pthread_mutex_lock(&(philo->meal));
	philo->last_meal = get_current_time();
	philo->is_eating = 1;
	philo->meals_eaten++;
	pthread_mutex_unlock(&(philo->meal));
	ft_usleep(philo->process->eat_time);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void	ft_sleep(t_philo *philo)
{
	display_msg(SLEEPING, philo);
	ft_usleep(philo->process->sl_duration);
}

void	*life_cycle(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	pthread_mutex_lock(&(philo->meal));
	philo->last_meal = philo->process->start_time;
	pthread_mutex_unlock(&(philo->meal));
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_end(philo->process))
	{
		eat(philo);
		ft_sleep(philo);
		display_msg(THINKING, philo);
	}
	return (NULL);
}
