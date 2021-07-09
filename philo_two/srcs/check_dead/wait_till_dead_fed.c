/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till_dead_fed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:36:46 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:36:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "../error/error.h"
#include <unistd.h>
#include "check_dead.h"
#include "../philo_thread/philo_thread.h"

void	wait_till_dead_or_fed(t_sim_model *mdl)
{
	int		dead_id;
	long	stop_time;
	t_philo	*p;
	int		res;
	int		is_last;

	is_last = 1;
	while (1)
	{
		usleep(1000);
		if ((res = is_dead_or_fed(&dead_id, &stop_time, mdl)) == STOP_DEAD)
		{
			p = mdl->philos + dead_id;
			print_status(p, stop_time, "died", is_last);
			pthread_mutex_unlock(p->check_dead_m);
			break ;
		}
		else if (res == STOP_FED)
		{
			print_message("All philosophers are fed\n", mdl, is_last);
			break ;
		}
	}
}
