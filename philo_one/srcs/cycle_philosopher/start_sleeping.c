/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:41:02 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:41:06 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../model/model.h"
#include "../philo_thread/philo_thread.h"

void	start_sleeping(t_philo *phil)
{
	print_status(phil, get_reletive_time_stamp(phil), "is sleeping", 0);
	wait_n_miliseconds(phil->time_to_sleep);
}
