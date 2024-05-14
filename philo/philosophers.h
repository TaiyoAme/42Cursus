/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:02:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/14 17:31:14 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "../libft/libft.h"

# include <bits/pthreadtypes.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define ERROR_PARAM 0

enum e_action
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD,
	L_FORK,
	R_FORK
};

typedef struct s_philo
{
	pthread_t			ph_thread;
	int					id;
	int					is_eating;
	int					is_sleeping;
	int					is_dead;
	int					meals_eaten;
//time
	size_t				last_meal;
	struct s_process	*process;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
}	t_philo;

typedef struct s_process
{
	int				ph_nb;
	int				die_in;
	int				eat_time;
	int				sl_duration;
	int				ready;
	int				round;
	int				o_dead;
	int				finished;
	size_t			start_time;
	t_philo			**philos;
	pthread_mutex_t	writing;
	pthread_mutex_t	*forks;
}	t_process;

t_process	*init_ph(char *nb, char *die_in, char *eat_t, char *sleep_t);
void		launch_threads(t_process *process);
void		display_msg(enum e_action action, t_philo *philo);
void		*life_cycle(void *ph);
void		free_process(t_process *process);
void		*monitor(void *process);

//UTILS
int			ft_nb_ret_size(const char *nptr);
size_t		get_current_time(void);
int			ft_usleep(size_t milliseconds);
void		ft_puttime_fd(size_t time, int fd);

#endif // !PHILOSOPHERS_H
