/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead_or_fed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:30:10 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 00:30:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "check_dead.h"
#include "../philo_thread/philo_thread.h"
#include <stdio.h>

static	int	check_if_daed_and_print_status(t_sim_model *m, t_philo *p)
{
	long	current_time;

	current_time = get_reletive_time_stamp(p);
	if (current_time - p->meal_time > m->time_to_die)
	{
		print_status(p, current_time, "died", 1);
		pthread_mutex_unlock(p->check_dead_m);
		return (STOP_DEAD);
	}
	return (CONTINUE);
}

static	int	is_fed(t_sim_model *m, t_philo *p)
{
	if (m->num_must_eat != -2 && p->num_ate < m->num_must_eat)
		return (0);
	return (1);
}

int			check_sim_end_and_print_status(t_sim_model *mdl)
{
	int		i;
	t_philo	*p;
	int		all_fed;

	all_fed = 1;
	i = 1;
	while (i <= mdl->philos_count && (p = mdl->philos + i))
	{
		pthread_mutex_lock(p->check_dead_m);
		if (check_if_daed_and_print_status(mdl, p) == STOP_DEAD)
			return (STOP_DEAD);
		all_fed *= is_fed(mdl, p);
		pthread_mutex_unlock(p->check_dead_m);
		i++;
	}
	if (mdl->num_must_eat != -2 && all_fed == 1)
	{
		print_message("All philosophers are fed\n", 1, mdl);
		return (STOP_FED);
	}
	return (CONTINUE);
}
