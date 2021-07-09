/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:40 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 13:04:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../error/error.h"
#include <pthread.h>
#include "../model/model.h"
#include <unistd.h>
#include "philo_thread.h"

static	int	start_odd_philosophers(t_sim_model *model)
{
	int			i;
	pthread_t	thread_id;
	void		*philo;
	int			r;

	i = 1;
	while (i <= model->philos_count)
	{
		philo = (void*)(model->philos + i);
		r = pthread_create(&thread_id, NULL, cycle_philisopher, philo);
		if (r != 0)
			return (ERROR_FAILED_CREATE_THREAD);
		r = pthread_detach(thread_id);
		if (r != 0)
			return (ERROR_FAILED_TO_DETACH_THREAD);
		i += 2;
	}
	return (0);
}

static	int	start_even_philosophers(t_sim_model *model)
{
	int			i;
	pthread_t	thread_id;
	void		*philo;
	int			r;

	i = 2;
	while (i <= model->philos_count)
	{
		philo = (void*)(model->philos + i);
		r = pthread_create(&thread_id, NULL, cycle_philisopher, philo);
		if (r != 0)
			return (ERROR_FAILED_CREATE_THREAD);
		r = pthread_detach(thread_id);
		if (r != 0)
			return (ERROR_FAILED_TO_DETACH_THREAD);
		i += 2;
	}
	return (0);
}

int			start_philosophers(t_sim_model *model)
{
	int	r;

	if ((r = start_odd_philosophers(model)) != 0)
		return (r);
	usleep(500);
	if ((r = start_even_philosophers(model)) != 0)
		return (r);
	return (r);
}
