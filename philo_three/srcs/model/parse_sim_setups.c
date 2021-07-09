/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sim_setups.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:51:37 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:51:38 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "../error/error.h"

static	int		are_phil_consts_parsed(t_sim_model *model)
{
	if (model->phil_num == -1)
		return (0);
	if (model->time_to_die == -1)
		return (0);
	if (model->time_to_eat == -1)
		return (0);
	if (model->time_to_sleep == -1)
		return (0);
	if (model->num_must_eat == -1)
		return (0);
	return (1);
}

static	long	atoi_unsigned(const char *str)
{
	long	result;

	if (*str == '\0')
		return (-1);
	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		if (result < 0)
			return (-1);
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (result);
}

int				parse_sim_setups(t_sim_model *model, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (ERROR_N_ARGS);
	model->phil_num = atoi_unsigned(argv[1]);
	model->time_to_die = atoi_unsigned(argv[2]);
	model->time_to_eat = atoi_unsigned(argv[3]);
	model->time_to_sleep = atoi_unsigned(argv[4]);
	if (argc == 6)
		model->num_must_eat = atoi_unsigned(argv[5]);
	else
		model->num_must_eat = -2;
	if (!are_phil_consts_parsed(model))
		return (ERROR_ARGS_PARSING);
	if (model->phil_num < 1)
		return (ERROR_PHILO_NUM_POSITIVE);
	return (NO_ERROR);
}
