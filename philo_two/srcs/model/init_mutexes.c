/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:51:00 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:51:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "../error/error.h"
#include <stdlib.h>

static	int				init_mutexes_arr(pthread_mutex_t *mem, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(mem + i, NULL) != 0)
		{
			destroy_mutexes_arr(mem, i);
			return (ERROR_INIT_MUTEXES);
		}
		i++;
	}
	return (NO_ERROR);
}

int						init_mutexes(t_sim_model *mdl)
{
	if ((pthread_mutex_init(&mdl->print_m, NULL)) != 0)
		return (ERROR_INIT_MUTEXES);
	if ((pthread_mutex_init(&mdl->take_forks_m, NULL)) != 0)
	{
		pthread_mutex_destroy(&mdl->print_m);
		return (ERROR_INIT_MUTEXES);
	}
	if ((init_mutexes_arr(mdl->check_dead_ms, mdl->phil_num)) != 0)
	{
		pthread_mutex_destroy(&mdl->print_m);
		pthread_mutex_destroy(&mdl->take_forks_m);
		return (ERROR_INIT_MUTEXES);
	}
	return (NO_ERROR);
}
