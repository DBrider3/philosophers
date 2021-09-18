/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:00:09 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 13:46:44 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo, int state)
{
	long long	time;

	time = get_cur_time() - philo->table->monitor->time_start;
	pthread_mutex_lock(&philo->table->change->print_key);
	if ((shared_read(&philo->table->change->mutex_die,&philo->table->monitor->die_flag)))
	{
		if (state == think)
		printf("%d %d is thinking\n", (int)time, philo->index + 1);
		else if (state == eat)
			printf("%d %d is eating\n", (int)time, philo->index + 1);
		else if (state == slp)
			printf("%d %d is sleeping\n", (int)time, philo->index + 1);
		else if (state == die)
		{
			printf("%d %d died\n", (int)time, philo->index + 1);
			shared_write(&philo->table->change->mutex_die, &philo->table->monitor->die_flag, ERROR);
		}
		else
			printf("%d %d has taken a fork \n", (int)time, philo->index + 1);
	}
	pthread_mutex_unlock(&philo->table->change->print_key);

}
