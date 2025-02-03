/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:44:17 by vlow              #+#    #+#             */
/*   Updated: 2025/02/04 01:11:53 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

static void	eat_routine(t_philo *philo);
static void	*single_philo(t_philo *philo);
static void	delay_offset(t_philo *philo);

void	*table_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (timer_ms() < philo->table->start_time)
		;
	if (!philo->table->tt_die)
		return (NULL);
	if (philo->table->t_num == 1)
		return (single_philo(philo));
	else if (philo->id % 2)
		delay_offset(philo);
	if (pthread_create(&philo->th2, NULL, &philo_status, philo))
		return (NULL);
	while (!exit_check(philo))
	{
		eat_routine(philo);
		if (!philo->times_eaten || exit_check(philo))
			break ;
		delay_ms(philo, philo->table->tt_sleep);
		print_status(philo, THINKING);
		delay_offset(philo);
	}
	if (pthread_join(philo->th2, NULL))
		printf("Error! Clear local thread\n");
	return (NULL);
}

static void	eat_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	print_status(philo, FORK_1);
	pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
	print_status(philo, FORK_2);
	print_status(philo, EATING);
	pthread_mutex_lock(&philo->lock_eat);
	philo->last_meal = timer_ms();
	pthread_mutex_unlock(&philo->lock_eat);
	delay_ms(philo, philo->table->tt_eat);
	pthread_mutex_lock(&philo->lock_eat);
	philo->times_eaten--;
	pthread_mutex_unlock(&philo->lock_eat);
	print_status(philo, SLEEPING);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
}

static void	*single_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
	print_status(philo, FORK_1);
	delay_ms(philo, philo->table->tt_die);
	print_status(philo, DIED);
	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
	return (NULL);
}

static void	delay_offset(t_philo *philo)
{
	int	offset;

	offset = (philo->table->tt_die - \
			(timer_ms() - philo->last_meal) - \
			philo->table->tt_eat) / 2;
	if (offset < 0)
		offset = 0;
	delay_ms(philo, offset);
}

void	*philo_status(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (timer_ms() < philo->table->start_time + 20)
		;
	while (1)
	{
		usleep(100);
		pthread_mutex_lock(&philo->lock_eat);
		i = philo->times_eaten;
		pthread_mutex_unlock(&philo->lock_eat);
		if (!i || dead_check(philo))
			break ;
	}
	return (NULL);
}
