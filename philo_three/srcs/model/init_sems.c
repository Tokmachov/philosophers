/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sems.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:34:41 by mac               #+#    #+#             */
/*   Updated: 2021/01/13 17:34:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "../error/error.h"
#include <semaphore.h>

int						init_sems(t_sim_model *mdl)
{
	sem_unlink(PRINT_S);
	sem_unlink(FORKS_S);
	sem_unlink(TAKE_FORKS_S);
	sem_unlink(LOG_TIME_S);
	if (!(mdl->print_s = sem_open(PRINT_S, O_CREAT, S_IWUSR, 1)))
		return (ERROR_INIT_SEM);
	if (!(mdl->forks_s = sem_open(FORKS_S, O_CREAT, S_IWUSR, mdl->phil_num)))
		return (ERROR_INIT_SEM);
	if (!(mdl->take_forks_s = sem_open(TAKE_FORKS_S, O_CREAT, S_IWUSR, 1)))
		return (ERROR_INIT_SEM);
	if (!(mdl->log_time_s = sem_open(LOG_TIME_S, O_CREAT, S_IWUSR, 1)))
		return (ERROR_INIT_SEM);
	return (NO_ERROR);
}
