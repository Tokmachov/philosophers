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
#include "philo_thread.h"
#include "../model/model.h"

void	print_message(char *msg, t_sim_model *mdl, int is_last)
{
	pthread_mutex_lock(&mdl->print_m);
	write(1, msg, ft_strlen(msg));
	if (!is_last)
		pthread_mutex_unlock(&mdl->print_m);
}

void	print_status(t_philo *p, MILISEC time_stamp, char *status, int is_last)
{
	int		index;
	char	*str;

	pthread_mutex_lock(p->print_m);
	index = write_positive_num_to_buff(g_print_buffer, time_stamp);
	str = " ms: ";
	while (*str)
		g_print_buffer[index++] = *str++;
	index += write_positive_num_to_buff(g_print_buffer + index, p->phil_id);
	g_print_buffer[index++] = ' ';
	while (*status)
		g_print_buffer[index++] = *status++;
	g_print_buffer[index++] = '\n';
	g_print_buffer[index] = '\0';
	write(STDOUT_FILENO, g_print_buffer, ft_strlen(g_print_buffer));
	if (!is_last)
		pthread_mutex_unlock(p->print_m);
}
