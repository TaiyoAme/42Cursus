/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:58:35 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/25 20:50:13 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int	entries_check(char *nb, char *die_in, char *diner_time, char *sl_duration)
{
	if (!ft_check_param(nb, 1, 200))
		return (printf("%s\n", ERROR_PHILOS), 0);
	else if (!ft_check_param(die_in, 60, -1)
		|| !ft_check_param(diner_time, 60, -1)
		|| !ft_check_param(sl_duration, 60, -1))
		return (printf("%s\n", ERROR_TIMER), 0);
	return (1);
}

void	launch_threads(t_process *process)
{
	pthread_t	thread;
	int			i;

	i = -1;
	process->start_time = get_current_time();
	if (process->ph_nb == 1)
	{
		display_msg(L_FORK, process->philos[0]);
		ft_usleep(process->die_in);
		display_msg(DEAD, process->philos[0]);
		return ;
	}
	while (++i < process->ph_nb)
	{
		pthread_create(&(process->philos[i]->ph_thread), \
			NULL, life_cycle, process->philos[i]);
	}
	i = -1;
	pthread_create(&thread, NULL, monitor, process);
	pthread_join(thread, NULL);
	while (++i < process->ph_nb)
	{
		pthread_join(process->philos[i]->ph_thread, NULL);
	}
}

void	display_msg(enum e_action action, t_philo *philo)
{
	size_t	time;

	if (check_end(philo->process))
		return ;
	pthread_mutex_lock(&(philo->process->writing));
	time = get_current_time() - philo->process->start_time;
	ft_puttime_fd(time, 1);
	if (action == EATING)
		printf(" %d is eating %d\n", philo->id, philo->meals_eaten + 1);
	else if (action == SLEEPING)
		printf(" %d is sleeping\n", philo->id);
	else if (action == THINKING)
		printf(" %d is thinking\n", philo->id);
	else if (action == L_FORK)
		printf(" %d has taken a fork\n", philo->id);
	else if (action == R_FORK)
		printf(" %d has taken a fork\n", philo->id);
	else if (action == DEAD)
		printf(" %d died\n", philo->id);
	pthread_mutex_unlock(&(philo->process->writing));
}

void	free_process(t_process *process)
{
	int	i;

	i = -1;
	while (++i < process->ph_nb)
	{
		free(process->philos[i]);
		pthread_mutex_destroy(&(process->forks[i]));
	}
	free(process->philos);
	free(process->forks);
	pthread_mutex_destroy(&(process->writing));
	free(process);
}

int	main(int argc, char *argv[])
{
	t_process	*process;

	argc--;
	argv++;
	if (argc != 4 && argc != 5)
		printf("%s\n", ERROR_PARAM);
	else if (entries_check(argv[0], argv[1], argv[2], argv[3]))
	{
		process = init_ph(argv[0], argv[1], argv[2], argv[3]);
		if (argc == 5 && ft_check_param(argv[4], 1, -1))
		{
			process->round = ft_atoi(argv[4]);
		}
		else if (argc == 5)
		{
			printf("%s\n", ERROR_MEAL_NUMBER);
			free_process(process);
			return (0);
		}
		launch_threads(process);
		free_process(process);
	}
	return (0);
}
