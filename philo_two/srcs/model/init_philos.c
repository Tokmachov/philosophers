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

#define NOT_INITIALIZED -1;

void	init_philos(t_sim_model *mdl)
{
	int				i;

	i = 1;
	while (i <= mdl->phil_num)
	{
		mdl->philos[i].phil_id = i;
		mdl->philos[i].sim_start_time = NOT_INITIALIZED;
		mdl->philos[i].meal_time = NOT_INITIALIZED;
		mdl->philos[i].time_to_eat = mdl->time_to_eat;
		mdl->philos[i].time_to_sleep = mdl->time_to_sleep;
		mdl->philos[i].num_ate = 0;
		mdl->philos[i].is_sim_finished = &mdl->is_sim_finished;
		mdl->philos[i].print_m = &mdl->print_m;
		mdl->philos[i].take_forks_m = &mdl->take_forks_m;
		mdl->philos[i].forks_sem = mdl->forks_s;
		mdl->philos[i].check_dead_m = &mdl->check_dead_ms[i - 1];
		i++;
	}
}
