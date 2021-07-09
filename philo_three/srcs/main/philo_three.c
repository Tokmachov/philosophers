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
#include "../philo_process/philo_process.h"
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

static	void	call_wait_for_n_ps(int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

static	void	kill_all_processes(t_sim_model *m)
{
	int		i;
	t_philo	*p;

	i = 1;
	while (i <= m->phil_num)
	{
		p = m->philos + i;
		kill(p->pid, SIGKILL);
		i++;
	}
}

static	int		complete_processes(t_sim_model *m)
{
	int procc_exit_stat;
	int i;

	i = 1;
	while (i <= m->phil_num)
	{
		waitpid(-1, &procc_exit_stat, 0);
		i++;
		if (WIFEXITED(procc_exit_stat))
		{
			if (WEXITSTATUS(procc_exit_stat) == STOP_FED)
			{
				sem_post(m->print_s);
				continue ;
			}
			if (WEXITSTATUS(procc_exit_stat) == STOP_DEAD)
			{
				kill_all_processes(m);
				call_wait_for_n_ps(m->phil_num - 1);
				return (STOP_DEAD);
			}
		}
	}
	return (STOP_FED);
}

int				main(int argc, char **argv)
{
	t_sim_model	model;
	int			result;

	if ((result = init_model(&model, argc, argv)) != NO_ERROR)
	{
		put_error(chose_error(result));
		return (result);
	}
	start_philo_processes(&model);
	result = complete_processes(&model);
	if (result == STOP_FED)
		print_message(STAT_FED, &model);
	clean_model(&model);
	return (0);
}
