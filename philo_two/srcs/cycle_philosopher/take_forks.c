/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:46:36 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:46:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "../philo_thread/philo_thread.h"
#include <semaphore.h>
#include <stdio.h>

void	take_forks(t_philo *phil)
{
	MILISEC	time_stamp;
	int		is_last;

	is_last = 0;
	pthread_mutex_lock(phil->take_forks_m);
	sem_wait(phil->forks_sem);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, "has taken a fork", is_last);
	sem_wait(phil->forks_sem);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, "has taken a fork", is_last);
	pthread_mutex_unlock(phil->take_forks_m);
}
