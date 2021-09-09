/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcho <dcho@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 16:05:07 by dcho              #+#    #+#             */
/*   Updated: 2021/08/31 16:07:26 by dcho             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == 0)
		return ((char*)s);
	return (0);
}

static int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static long long		ft_atoi(const char *str)
{
	long long	result;
	int			minus_chk;

	minus_chk = 1;
	result = 0;
	while (ft_strchr("\t\n\v\f\r ", *str))
		str++;
	if (*str == '-' || *str == '+')
	{
		*str == '-' ? minus_chk *= -1 : minus_chk;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			result += (*str - '0');
			if (ft_isdigit(*(str + 1)))
				result *= 10;
		}
		else
			return (0);
		str++;
	}
	return (result * minus_chk);
}

static int		argument_check(char *argv)
{
	long long	num;

	if (!(num = ft_atoi(argv)) || num >= 2147483647 || num < 1)
		return (ERROR);
	return ((int)num);
}

int		scan_main(int argc, char *argv[], t_option *op)
{
	int		i;
	int		result;

	if (argc > 6)
		return (ERROR);
	init_argument(op);
	i = 1;
	while (i < argc)
	{
		if (!(result = argument_check(argv[i])))
			return (ERROR);
		if (i == 1)
			op->num_philo = result;
		else if (i == 2)
			op->time_die = result;
		else if (i == 3)
			op->time_eat = result;
		else if (i == 4)
			op->time_sleep = result;
		else
			op->num_must_eat = result;
		i++;
	}
	return (OK);
}
