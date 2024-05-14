/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 16:58:35 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/14 18:53:37 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <pthread.h>
#include <stdio.h>

int	entries_check(char *nb, char *die_in, char *diner_time, char *sl_duration)
{
	if (ft_nb_ret_size(nb)
		&& ft_nb_ret_size(die_in)
		&& ft_nb_ret_size(diner_time)
		&& ft_nb_ret_size(sl_duration))
		return (1);
	return (0);
}

void	launch_threads(t_process *process)
{
	pthread_t	thread;
	int			i;

	i = -1;
	process->start_time = get_current_time();
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

	if (philo->is_dead)
		return ;
	pthread_mutex_lock(&(philo->process->writing));
	time = get_current_time() - philo->process->start_time;
	ft_puttime_fd(time, 1);
	if (action == EATING)
		printf(" | %d is eating\n", philo->id);
	else if (action == SLEEPING)
		printf(" | %d is sleeping\n", philo->id);
	else if (action == THINKING)
		printf(" | %d is thinking\n", philo->id);
	else if (action == L_FORK)
		printf(" | %d take his left_fork\n", philo->id);
	else if (action == R_FORK)
		printf(" | %d take his right_fork\n", philo->id);
	else if (action == DEAD)
		printf(" | %d died\n", philo->id);
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
		return (ERROR_PARAM);
	else if (entries_check(argv[0], argv[1], argv[2], argv[3]))
	{
		process = init_ph(argv[0], argv[1], argv[2], argv[3]);
		if (argc == 5 && ft_nb_ret_size(argv[4]))
		{
			process->round = ft_atoi(argv[4]);
		}
		else if (argc == 5)
		{}//FREE
		launch_threads(process);
		free_process(process);
	}
	return (0);
}
