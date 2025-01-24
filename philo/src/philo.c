/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/01/24 11:33:24 by vlow             ###   ########.fr       */
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

void	*table_routine(void *arg)
{
	// t_data *data;
	//
	// data = (t_data *)arg;
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->fork[])
	return NULL;
}

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
	pthread_mutex_init(&data.mutex, NULL);
	while (i < data.table.t_num)
	{
		// memset(&data.philo[i], 0, sizeof(t_philo));
		if (pthread_create(&data.philo[i].th, NULL, &table_routine, &data.philo[i]))
		{
			printf("Error! Creating Philo!\n");
			return (1);
		}
		data.philo[i].id = i;
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
	ft_printf("data.test = [%d]\n", data.test);




	return EXIT_SUCCESS;
}
