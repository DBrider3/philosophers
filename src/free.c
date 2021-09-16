/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:19:29 by dcho              #+#    #+#             */
/*   Updated: 2021/09/15 19:56:38 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static void	free_mutex(t_table *t)
{
	int		i;

	i = 0;
	while (i < t->op->num_philo)
	{
		pthread_mutex_unlock(&t->fork[i].mutex);
		pthread_mutex_destroy(&t->fork[i++].mutex);
	}
	pthread_mutex_unlock(&t->change->print_key);
	pthread_mutex_unlock(&t->change->mutex_die);
	pthread_mutex_unlock(&t->change->mutex_lasteat);
	pthread_mutex_destroy(&t->change->print_key);
	pthread_mutex_destroy(&t->change->mutex_die);
	pthread_mutex_destroy(&t->change->mutex_lasteat);
}

void		free_final(t_table *t)
{
	free_mutex(t);
	free(t->phs);
	free(t->thds);
	free(t->fork);
	free(t->change);
	free(t->monitor);
}
