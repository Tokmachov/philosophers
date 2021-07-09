/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:04:26 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 13:04:31 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../utils/utils.h"
#include "philo_process.h"
#include "../model/model.h"
#include <semaphore.h>

void	print_message(char *msg, t_sim_model *mdl)
{
	sem_wait(mdl->print_s);
	write(1, msg, ft_strlen(msg));
	write(1, "\n", 1);
	sem_post(mdl->print_s);
}

void	print_status(t_philo *phil, MILISEC time_stamp, char *status)
{
	int		index;
	char	*str;

	sem_wait(phil->print_s);
	index = write_positive_num_to_buff(g_print_buffer, time_stamp);
	str = " ms: ";
	while (*str)
		g_print_buffer[index++] = *str++;
	index += write_positive_num_to_buff(g_print_buffer + index, phil->phil_id);
	g_print_buffer[index++] = ' ';
	while (*status)
		g_print_buffer[index++] = *status++;
	g_print_buffer[index++] = '\n';
	g_print_buffer[index] = '\0';
	write(STDOUT_FILENO, g_print_buffer, ft_strlen(g_print_buffer));
	if (!phil->is_dead)
		sem_post(phil->print_s);
}
