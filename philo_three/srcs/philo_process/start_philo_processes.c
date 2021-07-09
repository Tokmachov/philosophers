/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philosophers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:40 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 13:04:41 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../error/error.h"
#include "../model/model.h"
#include <unistd.h>
#include "philo_process.h"

static	void	set_philos_sim_start_time(t_sim_model *m)
{
	int		i;
	MILISEC	sim_start_time;

	i = 1;
	sim_start_time = get_abs_time_stamp();
	while (i <= m->phil_num)
	{
		m->philos[i].sim_start_time = sim_start_time;
		i++;
	}
}

int				start_philo_processes(t_sim_model *m)
{
	int		i;
	t_philo *ph;

	set_philos_sim_start_time(m);
	i = 1;
	while (i <= m->phil_num)
	{
		ph = m->philos + i;
		if ((ph->pid = fork()) < 0)
			return (ERROR_PROCESS_CREATE);
		else if (ph->pid == 0)
			cycle_philosopher(ph);
		usleep(100);
		i++;
	}
	return (0);
}
