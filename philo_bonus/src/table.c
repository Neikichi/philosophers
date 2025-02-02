/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:44:17 by vlow              #+#    #+#             */
/*   Updated: 2025/02/02 14:40:34 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <unistd.h>

// static void	eat_routine(t_philo *philo);
// static void	*single_philo(t_philo *philo);

// void	*table_routine(void *arg)
// {
// 	t_philo	*philo;
//
// 	philo = (t_philo *)arg;
// 	if (!philo->table->tt_die)
// 		return (NULL);
// 	if (philo->table->t_num == 1)
// 		return (single_philo(philo));
// 	else if (philo->id % 2)
// 		delay_ms(philo, philo->table->tt_sleep);
// 	while (!exit_check(philo))
// 	{
// 		eat_routine(philo);
// 		if (!philo->times_eaten || exit_check(philo))
// 			break ;
// 		delay_ms(philo, philo->table->tt_sleep);
// 		print_status(philo, THINKING);
// 	}
// 	return (NULL);
// }
//
// static void	eat_routine(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
// 	print_status(philo, FORK_1);
// 	pthread_mutex_lock(&philo->table->forks[philo->fork[1]]);
// 	print_status(philo, FORK_2);
// 	print_status(philo, EATING);
// 	pthread_mutex_lock(&philo->table->lock_eat);
// 	philo->last_meal = timer_ms();
// 	pthread_mutex_unlock(&philo->table->lock_eat);
// 	delay_ms(philo, philo->table->tt_eat);
// 	pthread_mutex_lock(&philo->table->lock_eat);
// 	philo->times_eaten--;
// 	pthread_mutex_unlock(&philo->table->lock_eat);
// 	print_status(philo, SLEEPING);
// 	pthread_mutex_unlock(&philo->table->forks[philo->fork[1]]);
// 	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
// }
//
// static void	*single_philo(t_philo *philo)
// {
// 	pthread_mutex_lock(&philo->table->forks[philo->fork[0]]);
// 	print_status(philo, FORK_1);
// 	delay_ms(philo, philo->table->tt_die);
// 	print_status(philo, DIED);
// 	pthread_mutex_unlock(&philo->table->forks[philo->fork[0]]);
// 	return (NULL);
// }
#include <stdlib.h>
#include <stdio.h>
void	*philo_status(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		// sem_wait(philo->table->lock_eat);
		if (dead_check(philo))
		{
			// sem_wait(philo->table->lock_eat);
			break ;
		}
		// sem_post(philo->table->lock_eat);
	}
	return(NULL);
}
