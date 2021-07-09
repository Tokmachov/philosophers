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
#include "../philo_process/philo_process.h"

void	start_eating(t_philo *phil)
{
	sem_wait(phil->log_time_s);
	phil->meal_time = get_reletive_time_stamp(phil);
	sem_post(phil->log_time_s);
	print_status(phil, phil->meal_time, STAT_EAT);
	wait_n_miliseconds(phil->time_to_eat);
}
