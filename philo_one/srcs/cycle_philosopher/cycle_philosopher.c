/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_philosopher.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:40:19 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:40:21 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "cycle_philosopher_utils.h"
#include "../philo_thread/philo_thread.h"

void	*cycle_philisopher(void *p)
{
	t_philo	*phil;

	phil = (t_philo*)p;
	phil->meal_time = get_reletive_time_stamp(phil);
	while (1)
	{
		start_thinking(phil);
		take_forks(phil);
		start_eating(phil);
		put_back_forks(phil);
		start_sleeping(phil);
	}
	return (NULL);
}
