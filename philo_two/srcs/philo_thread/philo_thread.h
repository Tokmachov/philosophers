/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:15 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 13:04:17 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREAD_H
# define PHILO_THREAD_H

# include "../model/model.h"

int		start_philosophers(t_sim_model *model);

int		join_all_threads(t_sim_model *mdl);

void	*cycle_philisopher(void *philosopher);

MILISEC	get_reletive_time_stamp(t_philo *phil);

MILISEC	get_abs_time_stamp(void);

void	wait_n_miliseconds(long miliseconds);

void	print_status(t_philo *p, MILISEC time_stamp, char *status, int is_last);

void	print_message(char *msg, t_sim_model *mdl, int is_last);

#endif
