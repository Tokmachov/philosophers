/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:40:54 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:40:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../model/model.h"
#include <stdio.h>
#include "../philo_thread/philo_thread.h"

void	start_eating(t_philo *phil)
{
	int is_last;

	is_last = 0;
	pthread_mutex_lock(phil->check_dead_m);
	phil->meal_time = get_reletive_time_stamp(phil);
	pthread_mutex_unlock(phil->check_dead_m);
	print_status(phil, phil->meal_time, "is eating", is_last);
	wait_n_miliseconds(phil->time_to_eat);
}
