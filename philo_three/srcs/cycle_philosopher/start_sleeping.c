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
#include "../philo_process/philo_process.h"

void	start_sleeping(t_philo *phil)
{
	print_status(phil, get_reletive_time_stamp(phil), STAT_SLEEP);
	wait_n_miliseconds(phil->time_to_sleep);
}
