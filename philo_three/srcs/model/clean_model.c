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
	if (g_print_buffer)
		free(g_print_buffer);
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

void	clean_model(t_sim_model *model)
{
	clean_sem(model->print_s, PRINT_S);
	clean_sem(model->forks_s, FORKS_S);
	clean_sem(model->take_forks_s, TAKE_FORKS_S);
	free_model_memory(model);
}
