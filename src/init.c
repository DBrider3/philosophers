/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:02:36 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 20:17:39 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_argument(t_option *op)
{
	op->num_philo = -1;
	op->time_die = -1;
	op->time_eat = -1;
	op->time_sleep = -1;
	op->num_must_eat = -1;
}

static void	init_mutex(t_table *t)
{
	pthread_mutex_init(&t->change->print_key, NULL);
	pthread_mutex_init(&t->change->mutex_die, NULL);
	pthread_mutex_init(&t->change->mutex_lasteat, NULL);
}

static void	init_malloc(t_table *t)
{
	t->phs = NULL;
	t->thds = NULL;
	t->fork = NULL;
	t->change = NULL;
	t->monitor = NULL;
	t->phs = malloc(sizeof(t_philo) * t->op->num_philo);
	t->thds = malloc(sizeof(pthread_t) * t->op->num_philo);
	t->fork = malloc(sizeof(t_fork) * t->op->num_philo);
	t->change = malloc(sizeof(t_change));
	t->monitor = malloc(sizeof(t_monitor));
}

int	init(t_table *t)
{
	int		i;

	init_malloc(t);
	if (!(t->phs || t->thds || t->fork || t->change || t->monitor))
		return (ERROR);
	i = 0;
	while (i < t->op->num_philo)
	{
		t->phs[i].index = i;
		t->phs[i].eat_count = 0;
		t->phs[i].flag = 0;
		t->phs[i].last_eat = get_cur_time();
		pthread_mutex_init(&t->fork[i].mutex, NULL);
		i++;
	}
	init_mutex(t);
	t->monitor->time_start = get_cur_time();
	t->monitor->die_flag = OK;
	return (OK);
}
