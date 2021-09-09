/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:02:36 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 17:25:26 by dcho             ###   ########.fr       */
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

int		init(t_table *t)
{
	int		i;

	// 테이블안의 철학자 수 만큼 철학자 구조체 할당 해주기
	if (!(t->phs = malloc(sizeof(t_philo) * t->op->num_philo)))
		return (ERROR);
	// 테이블안의 철학자 수 만큼  철학자의 스레드 할당 해주기
	if (!(t->thds = malloc(sizeof(pthread_t) * t->op->num_philo)))
		return (ERROR);
	// 포크 생성
	if (!(t->fork = malloc(sizeof(t_fork) * t->op->num_philo)))
		return (ERROR);

	// 철학자 구조체 index, 포크 뮤텍스 초기화
	i = 0;
	while (i < t->op->num_philo)
	{
		t->phs[i].index = i + 1;
		t->phs[i].last_eat = get_cur_time();
		pthread_mutex_init(&t->fork[i++].mutex, NULL);
	}
	init_mutex(t);
	t->monitor->die_flag = OK;
}
