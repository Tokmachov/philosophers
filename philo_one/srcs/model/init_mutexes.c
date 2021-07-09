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

static	pthread_mutex_t	*init_mutexes_arr(int n)
{
	int				i;
	pthread_mutex_t	*mutexes;

	if (!(mutexes = malloc(sizeof(pthread_mutex_t) * n)))
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(mutexes + i, NULL) != 0)
		{
			destroy_mutexes_arr(mutexes, i);
			free(mutexes);
			return (NULL);
		}
		i++;
	}
	return (mutexes);
}

int						init_mutexes(t_sim_model *model)
{
	if (!(model->fork_ms = init_mutexes_arr(model->philos_count)))
		return (ERROR_INIT_FORKS);
	if ((pthread_mutex_init(&model->print_m, NULL)) != 0)
	{
		destroy_mutexes_arr(model->fork_ms, model->philos_count);
		free(model->fork_ms);
		return (ERROR_INIT_PRINT_MUTEX);
	}
	if (!(model->check_dead_ms = init_mutexes_arr(model->philos_count)))
	{
		destroy_mutexes_arr(model->fork_ms, model->philos_count);
		free(model->fork_ms);
		pthread_mutex_destroy(&model->print_m);
		return (ERROR_INIT_FORKS);
	}
	return (0);
}
