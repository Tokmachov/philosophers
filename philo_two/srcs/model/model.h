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
# define FORKS_S "/forks_sem"

typedef	struct	s_philosopher
{
	int				phil_id;
	MILISEC			sim_start_time;
	MILISEC			meal_time;
	MILISEC			time_to_sleep;
	MILISEC			time_to_eat;
	int				num_ate;
	int				*is_sim_finished;
	pthread_mutex_t	*print_m;
	pthread_mutex_t	*check_dead_m;
	pthread_mutex_t *take_forks_m;
	sem_t			*forks_sem;
}				t_philo;

typedef	struct	s_sim_model
{
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	long			phil_num;
	long			num_must_eat;
	int				is_sim_finished;
	pthread_t		*threads_ids;
	pthread_mutex_t	print_m;
	pthread_mutex_t	take_forks_m;
	pthread_mutex_t	*check_dead_ms;
	sem_t			*forks_s;
	t_philo			*philos;
}				t_sim_model;

int				init_model(t_sim_model *mdl, int argc, char **argv);

void			clean_model(t_sim_model *model);

void			clean_mutexes(t_sim_model *model);

void			destroy_mutexes_arr(pthread_mutex_t *fork_ms, int ms_count);

void			clean_sem(sem_t *sem, char *sem_name);

void			unblock_sems(t_sim_model *m);

void			free_model_memory(t_sim_model *mdl);

int				parse_sim_setups(t_sim_model *model, int argc, char **argv);

int				init_mutexes(t_sim_model *model);

void			init_philos(t_sim_model *mdl);

#endif
