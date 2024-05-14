/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:13:06 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/09 18:59:07 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->r_fork);
		display_msg(R_FORK, philo);
		pthread_mutex_lock(philo->l_fork);
		display_msg(L_FORK, philo);
	}
	else
	{
		pthread_mutex_lock(philo->l_fork);
		display_msg(L_FORK, philo);
		pthread_mutex_lock(philo->r_fork);
		display_msg(R_FORK, philo);
	}
}

void	eat(t_philo *philo)
{
	take_forks(philo);
	display_msg(EATING, philo);
	philo->is_eating = 1;
	ft_usleep(philo->process->eat_time);
	philo->meals_eaten++;
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	display_msg(SLEEPING, philo);
	ft_usleep(philo->process->sl_duration);
	display_msg(THINKING, philo);
}

void	*life_cycle(void *ph)
{
	t_philo	*philo;

	philo = (t_philo *)ph;
	philo->last_meal = philo->process->start_time;
	while (!philo->is_dead)
	{
		eat(philo);
	}
	return (NULL);
}
