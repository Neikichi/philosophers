/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:28:24 by vlow              #+#    #+#             */
/*   Updated: 2025/01/26 02:55:48 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int	exit_check(t_philo *philo)
{
	int	i;

	i = 0;
	sem_wait(philo->table->lock_end);
	if (philo->table->end)
		i = 1;
	sem_post(philo->table->lock_end);
	return (i);
}

int	exit_error(char *err, int ret)
{
	printf("%s", err);
	return (ret);
}

int	dead_check(t_philo *philo)
{
	sem_wait(philo->table->lock_eat);
	if (timer_ms() - philo->last_meal >= philo->table->tt_die)
	{
		print_status(philo, DIED);
		sem_wait(philo->table->lock_end);
		philo->table->end = 1;
		sem_post(philo->table->lock_end);
		sem_post(philo->table->lock_eat);
		return (1);
	}
	sem_post(philo->table->lock_eat);
	return (0);
}

// void	init_destroy(t_data *data)
// {
// 	int	i;
//
// 	i = 0;
// 	pthread_mutex_destroy(&data->table.lock_eat);
// 	pthread_mutex_destroy(&data->table.lock_print);
// 	pthread_mutex_destroy(&data->table.lock_end);
// 	while (i < data->table.t_num)
// 	{
// 		pthread_mutex_destroy(&data->table.forks[i]);
// 		i++;
// 	}
// }
