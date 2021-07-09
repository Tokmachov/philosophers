/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dead.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:22:25 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 00:22:37 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_DEAD_H
# define CHECK_DEAD_H

# include "../model/model.h"

void	wait_till_dead_or_fed(t_sim_model *mdl);

int		check_sim_end_and_print_status(t_sim_model *mdl);

# define CONTINUE 0
# define STOP_DEAD 1
# define STOP_FED 2

#endif
