/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:51:23 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:51:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_H
# define MODEL_H
# include <pthread.h>
# include <semaphore.h>

extern	char	*g_print_buffer;

# define MILISEC long

# define PRINT_S "/print_sem"

# define FORKS_S "/forks_sem"

# define TAKE_FORKS_S "/take_forks_sem"

# define LOG_TIME_S "/log_time_s"

# define CONTINUE 0

# define STOP_DEAD 1

# define STOP_FED 2

# define STAT_DEAD "died"

# define STAT_TAKE_FORK "has taken a fork"

# define STAT_EAT "is eating"

# define STAT_SLEEP "is sleeping"

# define STAT_THINK "is thinking"

# define STAT_FED "All philosophers are fed"

typedef	struct	s_philosopher
{
	int				phil_id;
	int				pid;
	MILISEC			sim_start_time;
	MILISEC			meal_time;
	MILISEC			time_to_sleep;
	MILISEC			time_to_eat;
	MILISEC			time_to_die;
	MILISEC			num_must_eat;
	int				num_ate;
	int				is_dead;
	sem_t			*print_s;
	sem_t			*take_forks_s;
	sem_t			*forks_s;
	sem_t			*log_time_s;
}				t_philo;

typedef	struct	s_sim_model
{
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			phil_num;
	long			num_must_eat;
	sem_t			*print_s;
	sem_t			*forks_s;
	sem_t			*take_forks_s;
	sem_t			*log_time_s;
	t_philo			*philos;
}				t_sim_model;

int				init_model(t_sim_model *mdl, int argc, char **argv);

void			clean_model(t_sim_model *model);

void			clean_mutexes(t_sim_model *model);

void			destroy_mutexes_arr(pthread_mutex_t *fork_ms, int ms_count);

void			clean_sem(sem_t *sem, char *sem_name);

void			free_model_memory(t_sim_model *mdl);

int				parse_sim_setups(t_sim_model *model, int argc, char **argv);

int				init_sems(t_sim_model *model);

void			init_philos(t_sim_model *mdl);

#endif
