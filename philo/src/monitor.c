/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:15:50 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/14 19:06:28 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <stdio.h>

int	check_death(t_process *process)
{
	int	i;

	i = -1;
	while (++i < process->ph_nb)
	{
		if (get_current_time() - process->philos[i]->last_meal >= \
			(size_t)process->die_in)
		{
			process->philos[i]->is_dead = 1;
			display_msg(DEAD, process->philos[i]);
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
		if (process->philos[i]->meals_eaten >= process->round)
		{
			process->philos[i]->is_dead = 1;
			process->finished++;
		}
	}
	if (process->finished == process->round)
		return (1);
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
			if (check_death(process))
				printf("end\n");
			if (all_ate(process))
				printf("end2\n");
			return (process);
		}
	}
	return (NULL);
}
