/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:44:17 by vlow              #+#    #+#             */
/*   Updated: 2025/02/04 01:29:56 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <unistd.h>

static void	eat_routine(t_philo *philo);
static void	single_philo(t_philo *philo);
static void	delay_offset(t_philo *philo);

int	table_routine(t_philo *philo)
{
	while (timer_ms() < philo->table->start_time)
		;
	sem_wait(philo->table->lock_eat);
	philo->last_meal = philo->table->start_time;
	sem_post(philo->table->lock_eat);
	if (!philo->table->tt_die)
		exit(1);
	if (philo->table->t_num == 1)
		single_philo(philo);
	else if (philo->id % 2)
		delay_offset(philo);
	if (pthread_create(&philo->th, NULL, &philo_status, philo))
		return (exit_error("Error! Init Philo Status\n", 0));
	while (!exit_check(philo))
	{
		eat_routine(philo);
	}
	if (pthread_join(philo->th, NULL))
		return (exit_error("Error! Init Thread Join\n", 0));
	exit(1);
}

static void	eat_routine(t_philo *philo)
{
	sem_wait(philo->table->lock_wait);
	sem_wait(philo->table->lock_forks);
	print_status(philo, FORK_1);
	sem_wait(philo->table->lock_forks);
	print_status(philo, FORK_2);
	print_status(philo, EATING);
	sem_wait(philo->table->lock_eat);
	philo->last_meal = timer_ms();
	sem_post(philo->table->lock_eat);
	delay_ms(philo, philo->table->tt_eat);
	sem_wait(philo->table->lock_eat);
	philo->times_eaten--;
	sem_post(philo->table->lock_eat);
	print_status(philo, SLEEPING);
	sem_post(philo->table->lock_forks);
	sem_post(philo->table->lock_forks);
	sem_post(philo->table->lock_wait);
	delay_ms(philo, philo->table->tt_sleep);
	print_status(philo, THINKING);
	delay_offset(philo);
}

static void	single_philo(t_philo *philo)
{
	sem_wait(philo->table->lock_forks);
	print_status(philo, FORK_1);
	delay_ms(philo, philo->table->tt_die);
	print_status(philo, DIED);
	sem_post(philo->table->lock_forks);
	exit(1);
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

	philo = (t_philo *)arg;
	while (1)
	{
		usleep(100);
		if (dead_check(philo))
			break ;
	}
	return (NULL);
}
