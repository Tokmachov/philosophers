/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:40:19 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:40:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "cycle_philosopher_utils.h"
#include "../philo_process/philo_process.h"
#include "../check_dead/check_dead.h"
#include <pthread.h>

void	*cycle_philosopher(t_philo *p)
{
	pthread_t thread_id;

	p->meal_time = get_reletive_time_stamp(p);
	pthread_create(&thread_id, NULL, check_if_philo_dead_or_fed, (void*)p);
	pthread_detach(thread_id);
	while (1)
	{
		start_thinking(p);
		take_forks(p);
		start_eating(p);
		put_back_forks(p);
		start_sleeping(p);
	}
	return (NULL);
}
