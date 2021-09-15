/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 16:00:09 by dcho              #+#    #+#             */
/*   Updated: 2021/09/13 15:08:11 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(t_philo *philo)
{
	long long	time;

	time = get_cur_time() - philo->table->start_time;
	// print flag를 세워야 함
	if (shared_read(&philo->table->change->mutex_die,&philo->table->monitor->die_flag))
	{
		pthread_mutex_lock(&philo->table->change->print_key);
		if (philo->state == think)
			printf("%d_in_ms %d is thinking\n", (int)time, philo->index);
		else if (philo->state == eat)
			printf("%d_in_ms %d is eating\n", (int)time, philo->index);
		else if (philo->state == slp)
			printf("%d_in_ms %d is sleeping\n", (int)time, philo->index);
		else if (philo->state == die)
			printf("%d_in_ms %d is died\n", (int)time, philo->index);
		else
			printf("%d_in_ms %d has taken \n", (int)time, philo->index);
		pthread_mutex_unlock(&philo->table->change->print_key);
	}
}