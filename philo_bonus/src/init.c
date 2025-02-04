/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:26:19 by vlow              #+#    #+#             */
/*   Updated: 2025/02/04 16:17:50 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

static void	setup_table(t_data *data);
static int	philo_parent(t_data *data);

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	setup_table(data);
	if (pthread_create(&data->th, NULL, &philo_monitor, data))
		return (exit_error("Error! Init Global Philo Monitor\n", 1));
	while (i < data->table.t_num)
	{
		sem_wait(data->table.lock_monitor);
		data->pid[i] = fork();
		sem_post(data->table.lock_monitor);
		if (data->pid[i] == -1)
			return (exit_error("Error! Invalid PID", 1));
		if (!data->pid[i])
			table_routine(&data->philo[i]);
		i++;
	}
	return (philo_parent(data));
}

static int	philo_parent(t_data *data)
{
	while (waitpid(0, NULL, 0) != -1)
		;
	if (!death_status())
	{
		sem_wait(data->table.lock_monitor);
		data->end = 1;
		sem_post(data->table.lock_monitor);
	}
	if (pthread_join(data->th, NULL))
		return (exit_error("Error! Init Thread Join\n", 1));
	close_semaphore(data);
	unlink_semaphore();
	return (0);
}

static void	setup_table(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->table.t_num)
	{
		data->philo[i].id = i;
		data->philo[i].table = &data->table;
		data->philo[i].times_eaten = data->table.to_eat;
		i++;
	}
	data->table.start_time = timer_ms() + (time_t)(data->table.t_num * 20);
}

int	init_data(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->table.t_num = ft_atoi(av[1]);
	if (data->table.t_num <= 0 || data->table.t_num > 200)
		return (0);
	data->table.tt_die = ft_atoi(av[2]);
	data->table.tt_eat = ft_atoi(av[3]);
	data->table.tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->table.to_eat = ft_atoi(av[5]);
	else
		data->table.to_eat = -1;
	return (1);
}

int	init_sem(t_data *data)
{
	unlink_semaphore();
	data->table.lock_monitor = sem_open("/lock_monitor", O_CREAT, 0666, 1);
	data->table.lock_end = sem_open("/lock_end", O_CREAT, 0666, 1);
	data->table.lock_print = sem_open("/lock_print", O_CREAT, 0666, 1);
	data->table.lock_eat = sem_open("/lock_eat", O_CREAT, 0666, 1);
	data->table.lock_forks = sem_open("/lock_forks", O_CREAT, 0666, \
													data->table.t_num);
	data->table.lock_wait = sem_open("/lock_wait", O_CREAT, 0666, \
												(data->table.t_num / 2));
	if (data->table.lock_end == SEM_FAILED || \
		data->table.lock_print == SEM_FAILED || \
		data->table.lock_eat == SEM_FAILED || \
		data->table.lock_wait == SEM_FAILED || \
		data->table.lock_monitor == SEM_FAILED)
		return (0);
	return (1);
}
