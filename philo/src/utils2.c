/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:22:27 by vlow              #+#    #+#             */
/*   Updated: 2025/02/04 01:12:29 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

static void	print_init(t_philo *philo, char *str, t_status status);

time_t	timer_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	delay_ms(t_philo *philo, time_t delay_time)
{
	time_t	delay;

	(void)philo;
	delay = timer_ms() + delay_time;
	while (timer_ms() < delay)
	{
		if (exit_check(philo))
			break ;
		usleep(100);
	}
}

void	print_status(t_philo *philo, t_status status)
{
	pthread_mutex_lock(&philo->table->lock_print);
	if (exit_check(philo))
	{
		pthread_mutex_unlock(&philo->table->lock_print);
		return ;
	}
	if (status == DIED)
		print_init(philo, "died", status);
	else if (status == EATING)
		print_init(philo, "is eating", status);
	else if (status == SLEEPING)
		print_init(philo, "is sleeping", status);
	else if (status == THINKING)
		print_init(philo, "is thinking", status);
	else if (status == FORK_1 || status == FORK_2)
		print_init(philo, "has taken a fork", status);
	pthread_mutex_unlock(&philo->table->lock_print);
}

static void	print_init(t_philo *philo, char *str, t_status status)
{
	const char	*status_colour;

	status_colour = COLOUR;
	if (status == DIED)
		status_colour = RED;
	else if (status == EATING)
		status_colour = GREEN;
	else if (status == SLEEPING)
		status_colour = PURPLE;
	else if (status == THINKING)
		status_colour = BLUE;
	else if (status == FORK_1 || status == FORK_2)
		status_colour = YELLOW;
	printf("%ld\t" CYAN "%d\t" COLOUR "%s%s" COLOUR "\n", \
	timer_ms() - philo->table->start_time, philo->id + 1, status_colour, str);
}
