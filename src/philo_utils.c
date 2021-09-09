/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:05:50 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 17:28:35 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		philo_create(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->op->num_philo)
	{
		table->phs[i].table = table;
		if (pthread_create(&table->thds[i], NULL, philo_main, &table->phs[i]))
			return (ERROR);
		i++;
	}
	return (OK);
}

int		philo_join(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->op->num_philo)
	{
		if (ptrhead_join(table->thds[i++], NULL))
			return (ERROR);
	}
}
