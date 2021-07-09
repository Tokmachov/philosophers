/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:45:58 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:46:00 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "../philo_process/philo_process.h"

void	start_thinking(t_philo *phil)
{
	MILISEC current_time_stamp;

	current_time_stamp = get_reletive_time_stamp(phil);
	print_status(phil, current_time_stamp, STAT_THINK);
}
