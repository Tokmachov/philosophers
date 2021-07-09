/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_till_dead_fed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:36:46 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:36:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "../error/error.h"
#include <unistd.h>
#include "check_dead.h"
#include "../philo_thread/philo_thread.h"

void	wait_till_dead_or_fed(t_sim_model *mdl)
{
	int		res;

	while (1)
	{
		usleep(1000);
		if ((res = check_sim_end_and_print_status(mdl)) == STOP_DEAD)
			break ;
		else if (res == STOP_FED)
			break ;
	}
}
