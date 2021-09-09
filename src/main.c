/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:02:53 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 21:31:52 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	monitoring(t_table *t)
{
	long long	diff;
	int			i;

	i = 0;
	while (1)
	{
		//t->monitor->time_cur = get_cur_time();
		diff = get_cur_time() -
		shared_read(&t->change->mutex_lasteat, &t->phs[i].last_eat);
		if (t->op->time_die <= diff)
		{
			t->phs[i].state = die;
			print(&t->phs[i]);
			// 프린트하고 공유자원 뮤텍스 걸어주기
			shared_write(&t->change->mutex_die, t->monitor->die_flag, ERROR);
			break;
		}
		i++;
		if (i == t->op->num_philo)
			i = 0;
	}
}

int			main(int argc, char *argv[])
{
	t_table		table;
	t_option	op;

	// 기본적으로 option 구조체에 인자 검증 후 받기
	if (!(scan_main(argc, argv, &op)))
		return (ERROR);
	table.op = &op;
	init(&table);
	philo_create(&table);
	// main thread에서 monitor를 두고 체크하기
	monitoring(&table);
	philo_join(&table);
	free_final(&table);
	return (0);
}
