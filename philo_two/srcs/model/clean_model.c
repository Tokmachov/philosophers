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
#include "../error/error.h"
#include <stdio.h>

void	free_model_memory(t_sim_model *mdl)
{
	if (mdl->philos)
		free(mdl->philos);
	if (mdl->threads_ids)
		free(mdl->threads_ids);
	if (g_print_buffer)
		free(g_print_buffer);
	if (mdl->check_dead_ms)
		free(mdl->check_dead_ms);
}

void	clean_sem(sem_t *sem, char *sem_name)
{
	int res_code;

	res_code = sem_close(sem);
	if (res_code != 0)
		printf("Error: failed to close forks_semaphore\n");
	res_code = sem_unlink(sem_name);
	if (res_code != 0)
		printf("Error: failed to unlink forks_semaphore\n");
}

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
	pthread_mutex_destroy(&model->take_forks_m);
	destroy_mutexes_arr(model->check_dead_ms, model->phil_num);
}

void	clean_model(t_sim_model *model)
{
	clean_mutexes(model);
	unblock_sems(model);
	clean_sem(model->forks_s, FORKS_S);
	free_model_memory(model);
}
