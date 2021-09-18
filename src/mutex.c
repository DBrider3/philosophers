/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:15:48 by dcho              #+#    #+#             */
/*   Updated: 2021/09/18 15:44:59 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
