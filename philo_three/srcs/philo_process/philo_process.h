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

#ifndef PHILO_PROCESS_H
# define PHILO_PROCESS_H

# include "../model/model.h"

int		start_philo_processes(t_sim_model *m);

void	*cycle_philosopher(t_philo *p);

MILISEC	get_reletive_time_stamp(t_philo *phil);

MILISEC	get_abs_time_stamp(void);

void	wait_n_miliseconds(long miliseconds);

void	print_status(t_philo *phil, MILISEC time_stamp, char *status);

void	print_message(char *msg, t_sim_model *mdl);

#endif
