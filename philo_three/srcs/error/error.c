/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:48:40 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:48:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils/utils.h"
#include "../error/error.h"

void	put_error(char *str)
{
	write(2, str, ft_strlen(str));
}

char	*chose_error(int code)
{
	if (code == ERROR_N_ARGS)
		return ("Error: wrong number of arguments\n");
	else if (code == ERROR_ARGS_PARSING)
		return ("Error: arguments must contain only numercics\n");
	else if (code == ERROR_INIT_SEM)
		return ("Error: failed to init forks semaphore\n");
	else if (code == ERROR_INIT_MUTEXES)
		return ("Error: failed to init mutexes\n");
	else if (code == ERROR_FAILED_ALLOC_MODEL_MEM)
		return ("Error: failed to to allocate model memory\n");
	else if (code == ERROR_PHILO_NUM_POSITIVE)
		return ("Error: number of philosophers must be positive\n");
	else if (code == ERROR_CLEAN_MODEL)
		return ("Error: failed to clean model\n");
	else if (code == ERROR_JOIN_THREAD)
		return ("Error: failed to join threadl\n");
	else if (code == ERROR_JOIN_THREAD)
		return ("Error: failed to create threadl\n");
	else
		return ("Error: undefined error occured\n");
}
