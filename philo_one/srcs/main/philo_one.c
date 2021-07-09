/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:58:46 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:58:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../model/model.h"
#include "../check_dead/check_dead.h"
#include "../error/error.h"
#include "../philo_thread/philo_thread.h"

int	main(int argc, char **argv)
{
	t_sim_model	model;
	int			result;

	if ((result = init_model(&model, argc, argv)) != NO_ERROR)
	{
		put_error(chose_error(result));
		return (result);
	}
	if ((result = start_philosophers(&model)) != NO_ERROR)
	{
		put_error(chose_error(result));
		clean_model(&model);
		return (result);
	}
	wait_till_dead_or_fed(&model);
	clean_model(&model);
	return (0);
}
