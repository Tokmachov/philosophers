/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 10:39:29 by mac               #+#    #+#             */
/*   Updated: 2021/01/11 10:39:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../model/model.h"
#include "../error/error.h"

int	join_all_threads(t_sim_model *mdl)
{
	int i;
	int res;

	i = 0;
	while (i < mdl->phil_num)
	{
		if ((res = pthread_join(mdl->threads_ids[i], NULL)) != 0)
			return (ERROR_JOIN_THREAD);
		i++;
	}
	return (0);
}
