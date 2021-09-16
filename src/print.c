/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:00:09 by dcho              #+#    #+#             */
/*   Updated: 2021/09/15 20:34:45 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo)
{
	long long	time;

	time = get_cur_time() - philo->table->monitor->time_start;
	if (shared_read(&philo->table->change->mutex_die,&philo->table->monitor->die_flag))
	{
		pthread_mutex_lock(&philo->table->change->print_key);
		if (philo->state == think)
			printf("%d %d is thinking\n", (int)time, philo->index + 1);
		else if (philo->state == eat)
			printf("%d %d is eating\n", (int)time, philo->index + 1);
		else if (philo->state == slp)
			printf("%d %d is sleeping\n", (int)time, philo->index + 1);
		else if (philo->state == die)
			printf("%d %d died\n", (int)time, philo->index);
		else
			printf("%d %d has taken a fork \n", (int)time, philo->index);
		pthread_mutex_unlock(&philo->table->change->print_key);
	}
}
