/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead_or_fed.c                                   :+:      :+:    :+:   */
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

static	int	is_dead(int *dead_id, MILISEC *dth_time, int phil_n, t_sim_model *m)
{
	t_philo	*p;
	MILISEC	current_time;

	p = m->philos + phil_n;
	current_time = get_reletive_time_stamp(p);
	if (current_time - p->meal_time >= m->time_to_die)
	{
		*dead_id = phil_n;
		*dth_time = current_time;
		return (1);
	}
	return (0);
}

int			is_dead_or_fed(int *dead_p_id, MILISEC *death_time, t_sim_model *m)
{
	int		i;
	t_philo	*p;
	int		all_fed;

	all_fed = 1;
	i = 1;
	while (i <= m->phil_num && (p = m->philos + i))
	{
		pthread_mutex_lock(p->check_dead_m);
		if ((m->is_sim_finished = is_dead(dead_p_id, death_time, i, m)))
			return (STOP_DEAD);
		if (m->num_must_eat != -2 && p->num_ate < m->num_must_eat)
			all_fed *= 0;
		pthread_mutex_unlock(p->check_dead_m);
		i++;
	}
	if (m->num_must_eat != -2 && all_fed == 1)
	{
		m->is_sim_finished = 1;
		return (STOP_FED);
	}
	return (CONTINUE);
}
