/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 11:48:47 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 11:48:48 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

void	put_error(char *str);
char	*chose_error(int code);

# define NO_ERROR 0

# define ERROR_N_ARGS 1

# define ERROR_ARGS_PARSING 2

# define ERROR_PHILO_NUM_POSITIVE 3

# define ERROR_INIT_SEM 4

# define ERROR_INIT_MUTEXES 5

# define ERROR_FAILED_ALLOC_MODEL_MEM 6

# define ERROR_CLEAN_MODEL 7

# define ERROR_JOIN_THREAD 8

# define ERROR_FAILED_CREATE_THREAD 9

#endif
