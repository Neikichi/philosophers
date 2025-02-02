/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:26:19 by vlow              #+#    #+#             */
/*   Updated: 2025/02/03 03:15:22 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>
#include <unistd.h>

static void	assign_fork(t_philo *philo);

int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->table.start_time = timer_ms() + (time_t)(data->table.t_num * 20);
	while (i < data->table.t_num)
	{
		data->philo[i].id = i;
		data->philo[i].table = &data->table;
		data->philo[i].times_eaten = data->table.to_eat;
		assign_fork(&data->philo[i]);
		pthread_mutex_lock(&data->table.lock_eat);
		data->philo[i].last_meal = data->table.start_time;
		pthread_mutex_unlock(&data->table.lock_eat);
		if (pthread_create(&data->philo[i].th, NULL, &table_routine, \
													&data->philo[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	assign_fork(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->t_num;
}

int	init_join_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->table.t_num)
	{
		if (pthread_join(data->philo[i].th, NULL))
			return (0);
		i++;
	}
	return (1);
}

int	init_data(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->table.t_num = ft_atoi(av[1]);
	if (data->table.t_num <= 0)
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

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->table.lock_eat, NULL);
	pthread_mutex_init(&data->table.lock_print, NULL);
	pthread_mutex_init(&data->table.lock_end, NULL);
	while (i < data->table.t_num)
	{
		if (pthread_mutex_init(&data->table.forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}
