/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:02:53 by dcho              #+#    #+#             */
/*   Updated: 2021/09/20 20:09:03 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	fork_unlock(t_table *t)
{
	int			i;

	i = 0;
	while (i < t->op->num_philo)
		pthread_mutex_unlock(&t->fork[i++].mutex);
}

static void	monitoring(t_table *t)
{
	long long	diff;
	int			i;

	i = 0;
	while (1)
	{
		diff = get_cur_time() - \
		shared_read(&t->change->mutex_lasteat, &t->phs[i].last_eat);
		if (t->op->num_must_eat != -1)
			if (!(shared_read(&t->change->mutex_die, &t->monitor->die_flag)))
				break ;
		if (t->op->time_die <= diff)
		{
			print(&t->phs[i], die);
			fork_unlock(t);
			break ;
		}
		i++;
		if (i == t->op->num_philo)
			i = 0;
	}
}

static int	philo_core(t_table *t)
{
	if (!(init(t)))
	{
		printf("Malloc Error!\n");
		free_final(t);
		return (ERROR);
	}
	if (!(philo_create(t)))
	{
		printf("Thread Create Error!\n");
		free_final(t);
		return (ERROR);
	}
	monitoring(t);
	if (!(philo_join(t)))
	{
		printf("Thread Join Error!\n");
		free_final(t);
		return (ERROR);
	}
	return (OK);
}

int	main(int argc, char *argv[])
{
	t_table		table;
	t_option	op;

	if (!(scan_main(argc, argv, &op)))
	{
		printf("Scan Error!\n");
		return (ERROR);
	}
	table.op = &op;
	if (!(philo_core(&table)))
		return (ERROR);
	free_final(&table);
	return (0);
}
