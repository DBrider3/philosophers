/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:13:05 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 21:33:50 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	philo->left = &philo->table->fork[philo->index];
	pthread_mutex_lock(philo->left);
	philo->state = fork;
	print(philo);
	philo->right = &philo->table->fork[(philo->index + 1) % philo->table->op->num_philo];
	pthread_mutex_lock(philo->right);
	philo->state = fork;
	print(philo);
	philo->state = eat;
	print(philo);
	time_pass(philo);
	shared_write(&philo->table->change->mutex_lasteat, &philo->last_eat, get_cur_time());
}

void	philo_think(t_philo *philo)
{
	philo->state = think;
	print(philo);
}

void	philo_sleep(t_philo *philo)
{
	philo->state = slp;
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	print(philo);
	time_pass(philo);
}

void	*philo_main(void *arg)
{
	t_philo		*philo;

	philo = (t_philo*)arg;

	while (shared_read(&philo->table->change->mutex_die,
	&philo->table->monitor->die_flag))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}

}
