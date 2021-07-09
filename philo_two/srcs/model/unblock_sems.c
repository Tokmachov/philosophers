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
#include <semaphore.h>

void	unblock_sems(t_sim_model *m)
{
	int i;

	i = 0;
	while (i <= m->phil_num)
	{
		sem_post(m->forks_s);
		i++;
	}
}
