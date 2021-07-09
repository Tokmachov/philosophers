/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_model.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:50:45 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 12:50:47 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "../error/error.h"
#include <stdlib.h>

char	*g_print_buffer;

int		init_model(t_sim_model *mdl, int argc, char **argv)
{
	int	r;

	if ((r = parse_sim_setups(mdl, argc, argv)) != 0)
		return (r);
	if ((r = init_mutexes(mdl)) != 0)
		return (r);
	if ((r = init_philos(mdl)) != 0)
	{
		clean_mutexes(mdl);
		return (r);
	}
	if (!(g_print_buffer = malloc(sizeof(char) * 1024)))
	{
		clean_mutexes(mdl);
		free(mdl->philos);
		return (ERROR_FAILED_ALLOC_BUF);
	}
	return (0);
}
