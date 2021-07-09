/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:50:45 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:50:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "../error/error.h"
#include <stdlib.h>

#include <semaphore.h>
#include <fcntl.h>

char	*g_print_buffer;

static	int	allocate_model_memory(t_sim_model *mdl)
{
	g_print_buffer = NULL;
	mdl->philos = NULL;
	if (!(mdl->philos = malloc(sizeof(t_philo) * (mdl->phil_num + 1))))
		return (ERROR_FAILED_ALLOC_MODEL_MEM);
	if (!(g_print_buffer = malloc(sizeof(char) * 1024)))
	{
		free_model_memory(mdl);
		return (ERROR_FAILED_ALLOC_MODEL_MEM);
	}
	return (NO_ERROR);
}

int			init_model(t_sim_model *mdl, int argc, char **argv)
{
	int	r;

	if ((r = parse_sim_setups(mdl, argc, argv)) != 0)
		return (r);
	if ((r = allocate_model_memory(mdl)) != 0)
		return (r);
	if ((r = init_sems(mdl)) != 0)
	{
		free_model_memory(mdl);
		return (r);
	}
	init_philos(mdl);
	return (0);
}
