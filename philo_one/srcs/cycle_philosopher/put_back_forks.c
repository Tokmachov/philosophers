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

void	put_back_forks(t_philo *phil)
{
	pthread_mutex_unlock(phil->left_fork_m);
	pthread_mutex_unlock(phil->right_fork_m);
	phil->num_ate += 1;
}
