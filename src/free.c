/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:19:29 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 20:17:26 by dcho             ###   ########.fr       */
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

void	free_final(t_table *t)
{
	if (t->fork != NULL)
		free_mutex(t);
	if (t->phs != NULL)
		free(t->phs);
	if (t->thds != NULL)
		free(t->thds);
	if (t->fork != NULL)
		free(t->fork);
	if (t->change != NULL)
		free(t->change);
	if (t->monitor != NULL)
		free(t->monitor);
}
