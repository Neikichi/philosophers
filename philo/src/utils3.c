/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:28:24 by vlow              #+#    #+#             */
/*   Updated: 2025/01/26 02:44:57 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

int	exit_check(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->table->lock_end);
	if (philo->table->end)
		i = 1;
	pthread_mutex_unlock(&philo->table->lock_end);
	return (i);
}

int	exit_error(char *err, int ret)
{
	printf("%s", err);
	return (ret);
}

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock_eat);
	if (timer_ms() - philo->last_meal >= philo->table->tt_die)
	{
		print_status(philo, DIED);
		pthread_mutex_lock(&philo->table->lock_end);
		philo->table->end = 1;
		pthread_mutex_unlock(&philo->table->lock_end);
		pthread_mutex_unlock(&philo->table->lock_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->table->lock_eat);
	return (0);
}

void	init_destroy(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->table.lock_eat);
	pthread_mutex_destroy(&data->table.lock_print);
	pthread_mutex_destroy(&data->table.lock_end);
	while (i < data->table.t_num)
	{
		pthread_mutex_destroy(&data->table.forks[i]);
		i++;
	}
}
