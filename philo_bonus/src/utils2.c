/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:54:40 by vlow              #+#    #+#             */
/*   Updated: 2025/02/03 02:29:14 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	close_semaphore(t_data *data)
{
	sem_close(data->table.lock_end);
	sem_close(data->table.lock_print);
	sem_close(data->table.lock_eat);
	sem_close(data->table.lock_forks);
	sem_close(data->table.lock_wait);
	sem_close(data->table.lock_monitor);
}

void	unlink_semaphore(void)
{
	sem_unlink("/lock_end");
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/lock_forks");
	sem_unlink("/lock_dead");
	sem_unlink("/lock_wait");
	sem_unlink("/lock_monitor");
}
