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
#include "check_dead.h"
#include "../philo_process/philo_process.h"
#include <stdlib.h>
#include <unistd.h>

static	int	is_fed(t_philo *p)
{
	if (p->num_must_eat != -2 && p->num_ate >= p->num_must_eat)
		return (STOP_FED);
	else
		return (CONTINUE);
}

static	int	is_dead(t_philo *p)
{
	MILISEC current_rel_time;
	MILISEC starve_time;

	current_rel_time = get_reletive_time_stamp(p);
	starve_time = current_rel_time - p->meal_time;
	if (starve_time > p->time_to_die)
	{
		p->is_dead = 1;
		print_status(p, current_rel_time, STAT_DEAD);
		return (STOP_DEAD);
	}
	else
		return (CONTINUE);
}

void		*check_if_philo_dead_or_fed(void *philo)
{
	t_philo	*p;

	p = (t_philo*)philo;
	while (1)
	{
		usleep(1000);
		sem_wait(p->log_time_s);
		if (is_dead(p) == STOP_DEAD)
		{
			sem_post(p->log_time_s);
			exit(STOP_DEAD);
		}
		if (is_fed(p) == STOP_FED)
		{
			sem_post(p->log_time_s);
			sem_wait(p->print_s);
			exit(STOP_FED);
		}
		sem_post(p->log_time_s);
	}
	return (NULL);
}
