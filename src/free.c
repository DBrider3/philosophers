/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:19:29 by dcho              #+#    #+#             */
/*   Updated: 2021/09/11 15:58:03 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_final(t_table *t)
{
	int		i;

	free(t->phs);
	free(t->thds);
	free(t->fork);
	pthread_mutex_destroy(&t->change->print_key);
	pthread_mutex_destroy(&t->change->mutex_die);
	pthread_mutex_destroy(&t->change->mutex_lasteat);
	i = 0;
	while (i < t->op->num_philo)
		pthread_mutex_destroy(&t->fork[i++].mutex);
}
