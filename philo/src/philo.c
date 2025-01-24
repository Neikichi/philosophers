/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/01/24 16:11:04 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/time.h>
#include "libft.h"

// void	free_thread(t_data *data)
// {
// 	int	i;
//
// 	i = 0;
// 	if (data->philo)
// 	{
// 		while (i < data->table.t_num)
// 		{
// 			if (data->philo[i])
// 				free(data->philo[i]);
// 			else
// 				break ;
// 			i++;
// 		}
// 		free(data->philo);
// 	}
// }

// void	free_all(t_data *data)
// {
	// free(data->philo);
// }

time_t	timer_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_sec / 1000));
}

void	delay_ms(t_philo *philo, time_t delay_time)
{
	time_t delay;

	(void)philo;
	delay = timer_ms() + delay_time;
	while (timer_ms() < delay)
	{
		// if dead or stop meal
		usleep(100);
	}
}

void	print_status(t_philo *philo, char *str, t_status status)
{
	const char	*status_colour;

	status_colour = COLOUR;
	if (status == DIED)
		status_colour = COLOUR;
	else if (status == EATING)
		status_colour = COLOUR;
	else if (status == SLEEPING)
		status_colour = COLOUR;
	else if (status == THINKING)
		status_colour = COLOUR;
	else if (status == FORK_1 || status == FORK_2)
		status_colour = COLOUR;
	printf("%ld\t" COLOUR "%d\t" COLOUR "%s%s\n" COLOUR, \
	timer_ms() - philo->table->start_time, philo->id, status_colour, str);
}

void	print_action(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->print);
	// if (is_exit_simulation(philo->table))
	// {
	// 	pthread_mutex_unlock(&philo->table->lock_print);
	// 	return ;
	// }
	if (status == DIED)
		print_status(philo, "died", status);
	else if (status == EATING)
		print_status(philo, "is eating", status);
	else if (status == SLEEPING)
		print_status(philo, "is sleeping", status);
	else if (status == THINKING)
		print_status(philo, "is thinking", status);
	else if (status == FORK_1 || status == FORK_2)
		print_status(philo, "has taken a fork", status);
	pthread_mutex_unlock(&philo->table->print);
}

void	init_data(t_data *data, int ac, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->table.t_num = ft_atoi(av[1]);
	data->table.tt_die = ft_atoi(av[2]);
	data->table.tt_eat = ft_atoi(av[3]);
	data->table.tt_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->table.opt_eat = ft_atoi(av[5]);
}

void	assign_fork(t_philo *philo)
{
	philo->fork[0] = philo->id;
	philo->fork[1] = (philo->id + 1) % philo->table->t_num;
}

void	*table_routine(void *arg)
{
	t_philo	*philo;
	int	i;

	philo = (t_philo *)arg;
	i = 0;
	philo->table->start_time = timer_ms();
	while (i < philo->table->t_num)
	{
		if (philo->id % 2)
			delay_ms(&philo[i], philo->table->tt_die);
		
		pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
		print_action(&philo[i], FORK_1);
		pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
		print_action(&philo[i], FORK_2);
		print_action(&philo[i], EATING);
		delay_ms(&philo[i], philo->table->tt_eat);
		print_action(&philo[i], SLEEPING);
		pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
		pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
		delay_ms(&philo[i], philo->table->tt_sleep);
		print_action(&philo[i], THINKING);
		// usleep(philo->table->tt_sleep);
	}
	return NULL;
}

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_init(&data->mutex, NULL);
	while (i < data->table.t_num)
	{
		if (pthread_mutex_init(&data->table.forks[i], NULL))
			return (0);
		i++;
	}
	return (1);
}

// int	init_philo(t_data *data)
// {
//
// }

// args: num of philo, tt die, tt eat, tt sleep, OPT: num of X must eat
// int main(void)
int main(int ac, char *av[])
{
	t_data data;

	if (ac < 5 || ac > 6)
	{
		printf("Error! Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [OPTIONAL: number_of_times_each_philosophers_must_eat]\n");
		return (1);
	}
	int i = 0;
	init_data(&data, ac, av);
	if (!init_mutex(&data))
	{
		return (printf("Error! Init Mutex\n") * 1);
	}
	while (i < data.table.t_num)
	{
		// memset(&data.philo[i], 0, sizeof(t_philo));
		if (pthread_create(&data.philo[i].th, NULL, &table_routine, &data.philo[i]))
		{
			printf("Error! Creating Philo!\n");
			return (1);
		}
		data.philo[i].id = i + 1;
		data.philo[i].table = &data.table;
		assign_fork(&data.philo[i]);
		i++;
	}
	i = 0;
	while (i < data.table.t_num)
	{
		if (pthread_join(data.philo[i].th, NULL))
		{
			printf("Error! Setting table\n");
			return (1);
		}
		i++;
	}
	pthread_mutex_destroy(&data.mutex);




	return EXIT_SUCCESS;
}
