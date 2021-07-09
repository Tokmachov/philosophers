/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:51:11 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:51:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include <stdlib.h>
#include "../error/error.h"
#include "../philo_thread/philo_thread.h"

#define NOT_INITIALIZED -1;

int	init_philos(t_sim_model *mdl)
{
	int				i;
	MILISEC			sim_abs_start_time;

	sim_abs_start_time = get_abs_time_stamp();
	mdl->philos = malloc(sizeof(t_philo) * (mdl->philos_count + 1));
	if (!mdl->philos)
		return (ERROR_FAILED_ALLOC_PHILS);
	i = 1;
	while (i <= mdl->philos_count)
	{
		mdl->philos[i].phil_id = i;
		mdl->philos[i].sim_start_time = sim_abs_start_time;
		mdl->philos[i].meal_time = NOT_INITIALIZED;
		mdl->philos[i].time_to_eat = mdl->time_to_eat;
		mdl->philos[i].time_to_sleep = mdl->time_to_sleep;
		mdl->philos[i].num_ate = 0;
		mdl->philos[i].is_dead = 0;
		mdl->philos[i].left_fork_m = &mdl->fork_ms[i - 1];
		mdl->philos[i].right_fork_m = &mdl->fork_ms[i % mdl->philos_count];
		mdl->philos[i].print_m = &mdl->print_m;
		mdl->philos[i].check_dead_m = &mdl->check_dead_ms[i - 1];
		i++;
	}
	return (0);
}
