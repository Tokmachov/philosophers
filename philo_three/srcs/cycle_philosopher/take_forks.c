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
#include "../philo_process/philo_process.h"
#include <semaphore.h>

void	take_forks(t_philo *phil)
{
	MILISEC	time_stamp;

	sem_wait(phil->take_forks_s);
	sem_wait(phil->forks_s);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, STAT_TAKE_FORK);
	sem_wait(phil->forks_s);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, STAT_TAKE_FORK);
	sem_post(phil->take_forks_s);
}
