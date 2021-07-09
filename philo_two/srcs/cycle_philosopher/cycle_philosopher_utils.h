/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_philosopher_utils.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:40:34 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:40:35 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYCLE_PHILOSOPHER_UTILS_H
# define CYCLE_PHILOSOPHER_UTILS_H

# include "../model/model.h"

void	start_eating(t_philo *phil);

void	put_back_forks(t_philo *phil);

void	start_eating(t_philo *phil);

void	start_thinking(t_philo *phil);

void	take_forks(t_philo *phil);

void	start_sleeping(t_philo *phil);

#endif
