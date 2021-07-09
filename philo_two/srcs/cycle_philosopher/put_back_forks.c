/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_back_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:40:43 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:40:45 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include "../model/model.h"
#include <semaphore.h>

void	put_back_forks(t_philo *phil)
{
	sem_post(phil->forks_sem);
	sem_post(phil->forks_sem);
	phil->num_ate += 1;
}
