/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <sjolynn@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 15:36:03 by mac               #+#    #+#             */
/*   Updated: 2021/01/09 15:36:05 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	int	count_digits(long num)
{
	int i;

	i = 1;
	while (num / 10)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int			write_positive_num_to_buff(char *buff, long num)
{
	int num_digits_written;
	int digit_index;

	num_digits_written = count_digits(num);
	digit_index = num_digits_written - 1;
	buff[digit_index + 1] = '\0';
	while (num / 10)
	{
		buff[digit_index] = '0' + num % 10;
		num /= 10;
		digit_index--;
	}
	buff[digit_index] = '0' + num % 10;
	return (num_digits_written);
}

size_t		ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
