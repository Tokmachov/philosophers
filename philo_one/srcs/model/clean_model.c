/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_model.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:42:50 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:42:52 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include <stdlib.h>

void	destroy_mutexes_arr(pthread_mutex_t *arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_destroy(arr + i);
		i++;
	}
}

void	clean_mutexes(t_sim_model *model)
{
	pthread_mutex_destroy(&model->print_m);
	destroy_mutexes_arr(model->fork_ms, model->philos_count);
	free(model->fork_ms);
	destroy_mutexes_arr(model->check_dead_ms, model->philos_count);
	free(model->check_dead_ms);
}

void	clean_model(t_sim_model *model)
{
	clean_mutexes(model);
	free(model->philos);
	free(g_print_buffer);
}
