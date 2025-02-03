/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:08:35 by vlow              #+#    #+#             */
/*   Updated: 2025/02/03 15:23:54 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/time.h>

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (exit_error(ERROR_SYNTAX, 1));
	if (!input_check(ac, av))
		return (exit_error("Error! Invalid Input\n", 1));
	if (!init_data(&data, ac, av))
		return (exit_error(ERROR_PHILO_COUNT, 1));
	if (!init_mutex(&data))
		return (exit_error("Error! Init Mutex\n", 1));
	if (!init_philo(&data))
		return (exit_error("Error! Init Philosophers\n", 1));
	if (!init_join_philo(&data))
		return (exit_error("Error! End Table\n", 1));
	init_destroy(&data);
	return (0);
}
