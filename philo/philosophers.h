/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehuang <hehuang@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:02:15 by hehuang           #+#    #+#             */
/*   Updated: 2024/05/25 19:30:56 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"

# include <bits/pthreadtypes.h>
# include <pthread.h>
# include <stddef.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

# define ERROR_PARAM "Error:\nNumber of arguments not valid"
# define ERROR_PHILOS "Error:\nPhilo number must be between 1 and 200"
# define ERROR_TIMER "Error:\nTimer value must be an int higher than 60"
# define ERROR_MEAL_NUMBER "Error:\nmeal number must be a postive value"

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
	int					finish;
//time
	size_t				last_meal;
	struct s_process	*process;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		meal;
}	t_philo;

typedef struct s_process
{
	int				ph_nb;
	int				die_in;
	int				eat_time;
	int				sl_duration;
	int				end;
	int				round;
	int				o_dead;
	int				finished;
	size_t			start_time;
	t_philo			**philos;
	pthread_mutex_t	writing;
	pthread_mutex_t	*forks;
	pthread_mutex_t	end_check;
}	t_process;

t_process	*init_ph(char *nb, char *die_in, char *eat_t, char *sleep_t);
void		launch_threads(t_process *process);
void		display_msg(enum e_action action, t_philo *philo);
void		*life_cycle(void *ph);
void		free_process(t_process *process);
void		*monitor(void *process);
int			check_death(t_process *process);
int			ft_end(t_process *process);
int			all_ate(t_process *process);
int			check_end(t_process *process);

//UTILS
int			ft_check_param(const char *nptr, int min, int max);
size_t		get_current_time(void);
int			ft_usleep(size_t milliseconds);
void		ft_puttime_fd(size_t time, int fd);

#endif // !PHILOSOPHERS_H
