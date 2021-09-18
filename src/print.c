/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:00:09 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 20:19:12 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_option(t_philo *philo, int *eat_count, long long time)
{
	if (philo->eat_count == philo->table->op->num_must_eat)
	{
		(*eat_count)++;
		if (*eat_count == philo->table->op->num_philo)
		{
			printf("All Philosopers have all eaten\n");
			shared_write(&philo->table->change->mutex_die, \
			&philo->table->monitor->die_flag, ERROR);
		}
	}
	else
		printf("%d %d is sleeping\n", (int)time, philo->index + 1);
}

void	print(t_philo *philo, int state)
{
	static int	eat_count;
	long long	time;

	time = get_cur_time() - philo->table->monitor->time_start;
	pthread_mutex_lock(&philo->table->change->print_key);
	if ((shared_read(&philo->table->change->mutex_die, \
	&philo->table->monitor->die_flag)))
	{
		if (state == think)
			printf("%d %d is thinking\n", (int)time, philo->index + 1);
		else if (state == eat)
			printf("%d %d is eating\n", (int)time, philo->index + 1);
		else if (state == slp)
			print_option(philo, &eat_count, time);
		else if (state == die)
		{
			printf("%d %d died\n", (int)time, philo->index + 1);
			shared_write(&philo->table->change->mutex_die, \
			&philo->table->monitor->die_flag, ERROR);
		}
		else
			printf("%d %d has taken a fork \n", (int)time, philo->index + 1);
	}
	pthread_mutex_unlock(&philo->table->change->print_key);
}
