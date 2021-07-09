/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:53 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 13:04:54 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "../model/model.h"
#include <unistd.h>

MILISEC	get_abs_time_stamp(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

MILISEC	get_reletive_time_stamp(t_philo *phil)
{
	MILISEC			time_stamp;

	time_stamp = get_abs_time_stamp() - phil->sim_start_time;
	return (time_stamp);
}

void	wait_n_miliseconds(long miliseconds)
{
	long	time_to;
	long	current;

	current = get_abs_time_stamp();
	time_to = current + miliseconds;
	usleep(miliseconds * 1000 - 7000);
	while (1)
	{
		current = get_abs_time_stamp();
		if (current >= time_to)
			break ;
		else
			usleep(100);
	}
}
