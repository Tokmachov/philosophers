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

void	take_forks(t_philo *phil)
{
	MILISEC	time_stamp;

	pthread_mutex_lock(phil->left_fork_m);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, "has taken a fork", 0);
	pthread_mutex_lock(phil->right_fork_m);
	time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, time_stamp, "has taken a fork", 0);
}
