/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:13:05 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 18:54:16 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_fork(t_philo *philo)
{
	int		fork_right;

	if (philo->index + 1 == philo->table->op->num_philo)
		fork_right = 0;
	else
		fork_right = philo->index + 1;
	philo->left = &philo->table->fork[philo->index];
	pthread_mutex_lock(&philo->left->mutex);
	print(philo, frk);
	philo->right = &philo->table->fork[fork_right];
	pthread_mutex_lock(&philo->right->mutex);
	philo->flag = 1;
	print(philo, frk);
}

void	philo_eat(t_philo *philo)
{
	print(philo, eat);
	time_pass(philo, eat);
	shared_write(&philo->table->change->mutex_lasteat, \
	&philo->last_eat, get_cur_time());
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
	if (philo->table->op->num_must_eat != -1)
		philo->eat_count++;
}

void	philo_think(t_philo *philo)
{
	print(philo, think);
}

void	philo_sleep(t_philo *philo)
{
	print(philo, slp);
	time_pass(philo, slp);
}

void	*philo_main(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while (shared_read(&philo->table->change->mutex_die, \
	&philo->table->monitor->die_flag))
	{
		philo_fork(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
