/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 14:13:05 by dcho              #+#    #+#             */
/*   Updated: 2021/09/15 19:45:54 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	int		ex;

	if ((ex = (philo->index) % (philo->table->op->num_philo)) == philo->table->op->num_philo)
		ex = 1;
	philo->left = &philo->table->fork[philo->index - 1];
	pthread_mutex_lock(&philo->left->mutex);
	philo->state = frk;
	print(philo);
	philo->right = &philo->table->fork[ex];
	pthread_mutex_lock(&philo->right->mutex);
	philo->state = frk;
	print(philo);
	philo->state = eat;
	print(philo);
	time_pass(philo);
	shared_write(&philo->table->change->mutex_lasteat, &philo->last_eat, get_cur_time());
	pthread_mutex_unlock(&philo->left->mutex);
	pthread_mutex_unlock(&philo->right->mutex);
}

void	philo_think(t_philo *philo)
{
	philo->state = think;
	print(philo);
}

void	philo_sleep(t_philo *philo)
{

	philo->state = slp;
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

		//printf("%d\n", (int)(philo->table->monitor->time_start - get_cur_time()));
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	printf("1\n");
	return (NULL);
}
