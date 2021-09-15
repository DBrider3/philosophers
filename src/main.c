/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:02:53 by dcho              #+#    #+#             */
/*   Updated: 2021/09/13 15:09:47 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitoring(t_table *t)
{
	long long	diff;
	int			i;

	i = 0;
	while (1)
	{

		diff = get_cur_time() -
		shared_read(&t->change->mutex_lasteat, &t->phs[i].last_eat);
		if (t->op->time_die <= diff)
		{
			t->phs[i].state = die;
			print(&t->phs[i]);
			shared_write(&t->change->mutex_die, &t->monitor->die_flag, ERROR);
			break ;
			//exit(0);
		}
		i++;
		if (i == t->op->num_philo)
			i = 0;
	}
}

int			main(int argc, char *argv[])
{
	t_table		table;
	t_option	op;

	if (!(scan_main(argc, argv, &op)))
		return (ERROR);
	table.op = &op;
	if (!(init(&table)))
		return (ERROR);
	philo_create(&table);
	monitoring(&table);
	philo_join(&table);
	free_final(&table);
	return (0);
}
