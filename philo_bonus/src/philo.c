/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/01/26 02:51:46 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int	main(int ac, char **av)
{
	t_data	data;
	pid_t	pid;
	int i = 0;
		
	if (ac < 5 || ac > 6)
		return (exit_error(ERROR_SYNTAX, 1));
	if (!input_check(ac, av))
		return (exit_error("Error! Invalid Input\n", 1));
	init_data(&data, ac, av);
	data.table.lock_end = sem_open("/lock_end", O_CREAT, 0666, 1);
	data.table.lock_print = sem_open("/lock_print", O_CREAT, 0666, 1);
	data.table.lock_eat = sem_open("/lock_eat", O_CREAT, 0666, 1);
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
	while (i < data.table.t_num)
{
		pid = fork();
		if (pid == -1)
			return (exit_error("Error! Invalid PID", 1));
		if (!pid)
		{
			if (!data.table.tt_die)
				exit(1);
			if (data.table.t_num == 1)
			{
				sem_wait(data.table.lock_forks);
				print_status(&data.philo[i], FORK_1);
				delay_ms(&data.philo[i], data.table.tt_die);
				print_status(&data.philo[i], DIED);
				sem_post(data.table.lock_forks);
				exit(0);
			}
			else if (i % 2)
				delay_ms(&data.philo[i], data.table.tt_sleep);
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

				if (!data.philo[i].times_eaten || exit_check(&data.philo[i]))
					exit(1);
				delay_ms(&data.philo[i], data.table.tt_sleep);
				print_status(&data.philo[i], THINKING);
			}
			exit(1);
		}
		if (data.table.t_num > 1)
			philo_status(&data);
		for (int i = 0; i < data.table.t_num; i++)
		{
			waitpid(-1, NULL, 0);
		}
		i++;
	}
	sem_close(data.table.lock_end);
	sem_close(data.table.lock_print);
	sem_close(data.table.lock_eat);
	sem_close(data.table.lock_forks);
	sem_unlink("/lock_end");
	sem_unlink("/lock_print");
	sem_unlink("/lock_eat");
	sem_unlink("/lock_forks");
	
















// 	if (!init_mutex(&data))
// 		return (exit_error("Error! Init Mutex\n", 1));
// 	if (!init_philo(&data))
// 		return (exit_error("Error! Init Philosophers\n", 1));
// 	if (data.table.t_num > 1)
// 		philo_status(&data);
// 	if (!init_join_philo(&data))
// 		return (exit_error("Error! End Table\n", 1));
// 	init_destroy(&data);

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
