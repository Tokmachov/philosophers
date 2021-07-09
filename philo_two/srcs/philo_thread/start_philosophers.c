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
#include "philo_thread.h"

int			start_philosophers(t_sim_model *model)
{
	int			i;
	pthread_t	thread_id;
	t_philo		*philo;
	int			r;
	MILISEC		sim_start_time;

	sim_start_time = get_abs_time_stamp();
	i = 1;
	while (i <= model->phil_num)
	{
		philo = model->philos + i;
		philo->sim_start_time = sim_start_time;
		r = pthread_create(&thread_id, NULL, cycle_philisopher, (void*)philo);
		if (r != 0)
			return (ERROR_FAILED_CREATE_THREAD);
		model->threads_ids[i - 1] = thread_id;
		i++;
	}
	return (0);
}
