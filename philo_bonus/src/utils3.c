/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:28:24 by vlow              #+#    #+#             */
/*   Updated: 2025/01/29 01:11:48 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

int	exit_check(t_philo *philo)
{
	if (!philo->times_eaten || dead_check(philo))
		return (1);
	return (0);
}

int	exit_error(char *err, int ret)
{
	printf("%s", err);
	return (ret);
}

int	death_status(void)
{
	sem_t *death;

	death = sem_open("/lock_dead", 0);
	if (death == SEM_FAILED)
		return (0);
	sem_close(death);
	return (1);
}

int	dead_check(t_philo *philo)
{
	sem_wait(philo->table->lock_eat);
	if (timer_ms() - philo->last_meal >= philo->table->tt_die)
	{
		print_status(philo, DIED);
		sem_wait(philo->table->lock_print);
		sem_wait(philo->table->lock_end);
		philo->table->lock_dead = sem_open("/lock_dead", O_CREAT, 0644, 0);
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
