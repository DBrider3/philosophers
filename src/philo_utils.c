/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 20:05:50 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 15:42:34 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	wait_create(t_philo *p)
{
	while (p->flag == 0)
		;
}

int	philo_create(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->op->num_philo)
	{
		table->phs[i].table = table;
		if (pthread_create(&table->thds[i], NULL, philo_main, &table->phs[i]))
			return (ERROR);
		if (i % 2 == 0)
			wait_create(&table->phs[i]);
		i++;
	}
	return (OK);
}

int	philo_join(t_table *table)
{
	int		i;

	i = 0;
	while (i < table->op->num_philo)
	{
		if (pthread_join(table->thds[i++], NULL))
			return (ERROR);
	}
	return (OK);
}
