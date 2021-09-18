/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 15:15:56 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 13:33:30 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(useconds_t time, t_table *t)
{
	long long	start_time;
	long long	cur_time;

	start_time = get_cur_time();
	while (1)
	{
		cur_time = get_cur_time();
		if (!(shared_read(&t->change->mutex_die, &t->monitor->die_flag))
		|| cur_time - start_time >= time)
			break ;
	}
}

void	time_pass(t_philo *philo, int state)
{
	int		delay;

	delay = 0;
	if (state == eat)
		delay = philo->table->op->time_eat;
	else if (state == slp)
		delay = philo->table->op->time_sleep;
	my_usleep(delay, philo->table);
}
