/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:28:24 by vlow              #+#    #+#             */
/*   Updated: 2025/02/04 16:26:57 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <fcntl.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	exit_check(t_philo *philo)
{
	if (!philo->times_eaten)
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
	sem_t	*death;

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
		sem_wait(philo->table->lock_end);
		philo->table->lock_dead = sem_open("/lock_dead", O_CREAT, 0644, 0);
		sem_post(philo->table->lock_end);
		sem_post(philo->table->lock_eat);
		exit(1);
	}
	sem_post(philo->table->lock_eat);
	return (0);
}

void	*philo_monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		usleep(100);
		sem_wait(data->table.lock_monitor);
		i = data->end;
		sem_post(data->table.lock_monitor);
		if (death_status() || i)
			break ;
	}
	i = 0;
	sem_wait(data->table.lock_end);
	while (i < data->table.t_num)
	{
		sem_wait(data->table.lock_monitor);
		if (!kill(data->pid[i], 0))
			kill(data->pid[i], SIGKILL);
		sem_post(data->table.lock_monitor);
		i++;
	}
	sem_post(data->table.lock_end);
	return (NULL);
}
