/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:15:48 by dcho              #+#    #+#             */
/*   Updated: 2021/08/26 18:45:15 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//int		died_read(pthread_mutex_t *mutex, int *ptr)
//{
//	int		result;

//	pthread_mutex_lock(mutex);
//	result = *ptr;
//	pthread_mutex_unlock(mutex);
//	return (result);
//}

//void	died_write(pthread_mutex_t *mutex, int *ptr, int value)
//{
//	pthread_mutex_lock(mutex);
//	*ptr = value;
//	pthread_mutex_unlock(mutex);
//}

long long	shared_read(pthread_mutex_t *mutex, long long *ptr)
{
	long long	result;

	pthread_mutex_lock(mutex);
	result = *ptr;
	pthread_mutex_unlock(mutex);
	return (result);
}

void	shared_write(pthread_mutex_t *mutex, long long *ptr, long long value)
{
	pthread_mutex_lock(mutex);
	*ptr = value;
	pthread_mutex_unlock(mutex);
}
