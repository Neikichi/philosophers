/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/02/01 18:40:06 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

void	*philo_monitor(void *arg)
{
	t_data *data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		usleep(100);
		if (death_status())
			break ;
	}
	i = 0;
	sem_wait(data->table.lock_end);
	while (i < data->table.t_num)
	{
		if (!kill(data->pid[i], 0))
			kill(data->pid[i], SIGKILL);
		i++;
	}
	sem_post(data->table.lock_end);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;
	int i = 0;
		
	if (ac < 5 || ac > 6)
		return (exit_error(ERROR_SYNTAX, 1));
	if (!input_check(ac, av))
		return (exit_error("Error! Invalid Input\n", 1));
	init_data(&data, ac, av);
	sem_unlink("/lock_end");
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/lock_forks");
	sem_unlink("/lock_dead");
	data.table.lock_end = sem_open("/lock_end", O_CREAT, 0666, 1);
	data.table.lock_print = sem_open("/lock_print", O_CREAT, 0666, 1);
	data.table.lock_eat = sem_open("/lock_eat", O_CREAT, 0666, 1);
	// data.table.lock_dead = sem_open("/lock_dead", O_CREAT, 0666, 0);
	data.table.lock_forks = sem_open("/lock_forks", O_CREAT, 0666, data.table.t_num);
	if (data.table.lock_end == SEM_FAILED || data.table.lock_print == SEM_FAILED || data.table.lock_eat == SEM_FAILED)
		return (exit_error("Error! Init Sem\n", 1));
	while (i < data.table.t_num)
	{
		data.philo[i].id = i;
		data.philo[i].table = &data.table;
		data.philo[i].times_eaten = data.table.to_eat;
		i++;
	}
	i = 0;
	data.table.start_time = timer_ms();
	if (pthread_create(&data.th, NULL, &philo_monitor, &data))
		return (exit_error("Error! Init Global Philo Monitor\n", 1));
	while (i < data.table.t_num)
	{
		data.pid[i] = fork();
		if (data.pid[i] == -1)
			return (exit_error("Error! Invalid PID", 1));
		if (!data.pid[i])
		{
			sem_wait(data.table.lock_eat);
			data.philo[i].last_meal = timer_ms();
			sem_post(data.table.lock_eat);
			if (!data.table.tt_die)
				exit(1);
			if (data.table.t_num == 1)
			{
				sem_wait(data.table.lock_forks);
				print_status(&data.philo[i], FORK_1);
				delay_ms(&data.philo[i], data.table.tt_die);
				print_status(&data.philo[i], DIED);
				sem_post(data.table.lock_forks);
				exit(1);
			}
			else if (i % 2)
				delay_ms(&data.philo[i], data.table.tt_sleep);
			if (pthread_create(&data.philo[i].th, NULL, &philo_status, &data.philo[i]))
				return (exit_error("Error! Init Philo Status\n", 1));
			while (!exit_check(&data.philo[i]))
			{
				sem_wait(data.table.lock_forks);
				print_status(&data.philo[i], FORK_1);
				sem_wait(data.table.lock_forks);
				print_status(&data.philo[i], FORK_2);
				print_status(&data.philo[i], EATING);
				sem_wait(data.table.lock_eat);
				data.philo[i].last_meal = timer_ms();
				sem_post(data.table.lock_eat);
				delay_ms(&data.philo[i], data.table.tt_eat);
				sem_wait(data.table.lock_eat);
				data.philo[i].times_eaten--;
				sem_post(data.table.lock_eat);
				print_status(&data.philo[i], SLEEPING);
				sem_post(data.table.lock_forks);
				sem_post(data.table.lock_forks);

				// if (exit_check(&data.philo[i]))
				// 	break ;
				delay_ms(&data.philo[i], data.table.tt_sleep);
				print_status(&data.philo[i], THINKING);
				delay_ms(&data.philo[i], data.table.tt_sleep / 2);
			}
			if (pthread_join(data.philo[i].th, NULL))
				return (exit_error("Error! Init Thread Join\n", 1));
			exit(1);
		}
		i++;
	}
	while (waitpid(0, NULL, 0) != -1)
		;
	if (pthread_join(data.th, NULL))
		return (exit_error("Error! Init Thread Join\n", 1));
	sem_close(data.table.lock_end);
	sem_close(data.table.lock_print);
	sem_close(data.table.lock_eat);
	sem_close(data.table.lock_forks);
	sem_unlink("/lock_end");
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/lock_forks");
	sem_unlink("/lock_dead");
	return (0);
}
























// int	main(int ac, char *av[])
// {
// 	t_data	data;
//
// 	if (ac < 5 || ac > 6)
// 		return (exit_error(ERROR_SYNTAX, 1));
// 	if (!input_check(ac, av))
// 		return (exit_error("Error! Invalid Input\n", 1));
// 	init_data(&data, ac, av);
// 	if (!init_mutex(&data))
// 		return (exit_error("Error! Init Mutex\n", 1));
// 	if (!init_philo(&data))
// 		return (exit_error("Error! Init Philosophers\n", 1));
// 	if (data.table.t_num > 1)
// 		philo_status(&data);
// 	if (!init_join_philo(&data))
// 		return (exit_error("Error! End Table\n", 1));
// 	init_destroy(&data);
// 	return (0);
// }
