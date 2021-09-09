/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 16:06:43 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 21:40:58 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

# define ERROR 0
# define OK 1
typedef struct		s_option
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_must_eat;
}					t_option;

typedef enum		e_state
{
	think,
	eat,
	slp,
	die,
	fork
}					t_state;

typedef struct		s_fork
{
	pthread_mutex_t mutex;
}					t_fork;


typedef struct		s_philo
{
	int				index;
	t_state			state;
	long long		last_eat;
	t_fork			*left;
	t_fork			*right;
	t_table			*table;
}					t_philo;

typedef struct		s_monitor
{
	long long		time_cur;
	long long		die_flag;
}					t_monitor;

// 쓰는 이유는 die flag, lasteat이 공유자원이기 때문이다.
typedef struct		s_change
{
	pthread_mutex_t	print_key;
	pthread_mutex_t mutex_die;
	pthread_mutex_t mutex_lasteat;
}					t_change;

typedef struct		s_table
{
	t_philo			*phs;
	t_fork			*fork;
	pthread_t		*thds;
	t_monitor		*monitor;
	t_change		*change;
	t_option		*op;
	//pthread_mutex_t	print_key;
}					t_table;

int			scan_main(int argc, char *argv[], t_option *op);
void		init_argument(t_option *op);
int			init(t_table *t);
int			philo_create(t_table *table);
int			philo_join(t_table *table);
void	free_final(t_table *t);
void	*philo_main(void *arg);

void			print(t_philo *philo);

// mutex
//int				died_read(pthread_mutex_t *mutex, int *ptr);
//void			died_write(pthread_mutex_t *mutex, int *ptr, int value);
// 공유 자원 문제 해결하는 것
long long	shared_read(pthread_mutex_t *mutex, long long *ptr);
void	shared_write(pthread_mutex_t *mutex, long long *ptr, long long value);

// time
long long	get_cur_time(void);
void	my_usleep(useconds_t time, t_table *t);
int		time_pass(t_philo *philo);

#endif
